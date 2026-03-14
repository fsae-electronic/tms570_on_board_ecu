#include "ui_touch.h"
#include "pages.h"

void delay (int ticks)
{
    for (volatile int i = 0; i < ticks * 1000; i++);
}


// Detecta si hay toque en la pantalla
static int eve_key_detect(Bridgetek_EVE2 &eve)
{
    int key_detect = 0;
    if (!(eve.LIB_MemRead16(eve.REG_TOUCH_SCREEN_XY) & 0x8000)) {
        key_detect = 1;
    }
    return key_detect;
}

// Lee el tag del toque
int eve_read_tag(Bridgetek_EVE2 &eve, uint8_t *key)
{
    uint8_t Read_tag;
    int key_detect = 0;

    Read_tag = eve.LIB_MemRead8(eve.REG_TOUCH_TAG);
    if (!(eve.LIB_MemRead16(eve.REG_TOUCH_SCREEN_XY) & 0x8000)) 
    {
        key_detect = 1;
        *key = Read_tag;
    }
    
    // Resetear TAG a 0 para permitir detectar el siguiente toque
    eve.LIB_MemWrite8(eve.REG_TOUCH_TAG, 0);

    return key_detect;
}

// Calibración de pantalla táctil
int eve_calibrate(Bridgetek_EVE2 &eve)
{
    // Esperar a que se suelte cualquier toque previo
    while (eve_key_detect(eve)) {
        delay(10);
    }
    delay(500);

    // Mostrar pantalla de calibración
    eve.LIB_BeginCoProList();
    eve.CMD_DLSTART();
    eve.CLEAR_COLOR_RGB(0, 0, 0);
    eve.CLEAR(1, 1, 1);
    eve.COLOR_RGB(255, 255, 255);
    eve.CMD_TEXT(
        eve.DISP_WIDTH()/2, 
        eve.DISP_HEIGHT()/2,
        28, 
        eve.OPT_CENTERX | eve.OPT_CENTERY,
        "Please tap on the dots"
    );
    eve.CMD_CALIBRATE(0);
    eve.LIB_EndCoProList();
    
    if (eve.LIB_AwaitCoProEmpty() != 0) {
        return -1;
    }

    // Guardar los parámetros de calibración
    uint32_t calib_a = eve.LIB_MemRead32(eve.REG_TOUCH_TRANSFORM_A);
    uint32_t calib_b = eve.LIB_MemRead32(eve.REG_TOUCH_TRANSFORM_B);
    uint32_t calib_c = eve.LIB_MemRead32(eve.REG_TOUCH_TRANSFORM_C);
    uint32_t calib_d = eve.LIB_MemRead32(eve.REG_TOUCH_TRANSFORM_D);
    uint32_t calib_e = eve.LIB_MemRead32(eve.REG_TOUCH_TRANSFORM_E);
    uint32_t calib_f = eve.LIB_MemRead32(eve.REG_TOUCH_TRANSFORM_F);

    // Aplicar los parámetros de calibración
    eve.LIB_MemWrite32(eve.REG_TOUCH_TRANSFORM_A, calib_a);
    eve.LIB_MemWrite32(eve.REG_TOUCH_TRANSFORM_B, calib_b);
    eve.LIB_MemWrite32(eve.REG_TOUCH_TRANSFORM_C, calib_c);
    eve.LIB_MemWrite32(eve.REG_TOUCH_TRANSFORM_D, calib_d);
    eve.LIB_MemWrite32(eve.REG_TOUCH_TRANSFORM_E, calib_e);
    eve.LIB_MemWrite32(eve.REG_TOUCH_TRANSFORM_F, calib_f);

    // Reset del controlador de toque
    eve.LIB_MemWrite8(eve.REG_CPURESET, 2);
    eve.LIB_MemWrite8(eve.REG_CPURESET, 0);

    delay(500);
    return 0;
}

// helper para leer posición de toque (devuelve true si hay toque)
bool eve_get_xy(Bridgetek_EVE2 &eve, uint16_t *x, uint16_t *y)
{
    uint32_t val = eve.LIB_MemRead32(eve.REG_TOUCH_SCREEN_XY);
    // bit31==1 indica sin toque
    if (val & 0x80000000)
        return false;
    *x = (val >> 16) & 0xFFFF;
    *y = val & 0xFFFF;
    return true;
}

void ui_handle_touch(Bridgetek_EVE2 &eve, dashboard_data_t *data)
{
    static uint8_t last_key = 0;
    static bool tracking_swipe = false;
    static uint16_t swipe_x0 = 0;
    static uint16_t last_x = 0;

    uint8_t key;
    uint16_t tx, ty;

    if (eve_key_detect(eve)) {
        // hay contacto; actualizar swipe y tag
        eve_get_xy(eve, &tx, &ty);
        last_x = tx;

        if (!tracking_swipe) {
            tracking_swipe = true;
            swipe_x0 = tx;
        }

        if (eve_read_tag(eve, &key)) {
            last_key = key;
        }
    } else {
        // toque liberado
        if (last_key != 0) {
            // acción de botón al soltar
            switch (last_key) {
                case 1:
                    data->traction_on = !data->traction_on;
                    break;
                case 2:
                    data->mode = !data->mode;
                    break;
                case 3:
                    data->drive_enabled = !data->drive_enabled;
                    break;
                case 10: current_page = PAGE_GRAPH; current_graph = GRAPH_M1_V; break;
                case 11: current_page = PAGE_GRAPH; current_graph = GRAPH_M1_I; break;
                case 12: current_page = PAGE_GRAPH; current_graph = GRAPH_M1_T; break;
                case 13: current_page = PAGE_GRAPH; current_graph = GRAPH_BAT_V; break;
                case 14: current_page = PAGE_GRAPH; current_graph = GRAPH_M2_V; break;
                case 15: current_page = PAGE_GRAPH; current_graph = GRAPH_M2_I; break;
                case 16: current_page = PAGE_GRAPH; current_graph = GRAPH_M2_T; break;
                case 17: current_page = PAGE_GRAPH; current_graph = GRAPH_BAT_I; break;
                case 18: current_page = PAGE_GRAPH; current_graph = GRAPH_STEER; break;
                case 19: current_page = PAGE_GRAPH; current_graph = GRAPH_TPS; break;
                case 20: current_page = PAGE_GRAPH; current_graph = GRAPH_FRONT_BRK; break;
                case 21: current_page = PAGE_GRAPH; current_graph = GRAPH_REAR_BRK; break;
                case 22: current_page = PAGE_GRAPH; current_graph = GRAPH_FL_SPD; break;
                case 23: current_page = PAGE_GRAPH; current_graph = GRAPH_FR_SPD; break;
                case 24: current_page = PAGE_GRAPH; current_graph = GRAPH_RL_SPD; break;
                case 25: current_page = PAGE_GRAPH; current_graph = GRAPH_RR_SPD; break;
                case 30: current_page = PAGE_TELEMETRY; current_graph = GRAPH_NONE; break;
                case 40: break;
                case 41: break;
                case 42: data->traction_on = !data->traction_on; break;
                case 43: data->mode = !data->mode; break;
                case 44: data->drive_enabled = !data->drive_enabled; break;
                case 45: data->telemetry_enabled = !data->telemetry_enabled; break;
                case 46: break;
                case 47: break;
                case 48: break;
                case 49: eve_calibrate(eve); break;
                case 50: break;
                case 51: break;
            }
            last_key = 0;
        }

        if (tracking_swipe) {
            int16_t dx = (int16_t)last_x - (int16_t)swipe_x0;
            const int16_t threshold = 50;
            if (dx > threshold) {
                // swipe hacia la derecha -> siguiente página
                int np = (int)current_page + 1;
                if (np > PAGE_DEBUG) np = PAGE_RACE;
                current_page = (ui_page_t)np;
            } else if (dx < -threshold) {
                // swipe hacia la izquierda -> página anterior
                int np = (int)current_page - 1;
                if (np < PAGE_RACE) np = PAGE_DEBUG;
                current_page = (ui_page_t)np;
            }
            tracking_swipe = false;
        }
    }
}
