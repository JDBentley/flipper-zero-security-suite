// Core flipper runtime
#include <furi.h>
// GUI System
#include <gui/gui.h>
// Input system
#include <input/input.h>

// Canvas is the drawing surface the flipper uses
static void draw_callback(Canvas* canvas, void* ctx) {
    UNUSED(ctx);
    canvas_clear(canvas);
    canvas_set_font(canvas, FontPrimary);
    canvas_draw_str(canvas, 10, 20, "Hello from Jesse");
    canvas_set_font(canvas, FontSecondary);
    canvas_draw_str(canvas, 10, 35, "Flipper Zero SDK");
    canvas_draw_str(canvas, 10, 50, "Phase 1 Complete");
}

// Puts the button event into our queue for the main loop to read
static void input_callback(InputEvent* input_event, void* ctx) {
    FuriMessageQueue* event_queue = ctx;
    furi_message_queue_put(event_queue, input_event, FuriWaitForever);
}

// The flipper calls this function when the app opens
int32_t hello_world_app(void* p) {
    UNUSED(p);

    // Start of the queue
    FuriMessageQueue* event_queue = furi_message_queue_alloc(8, sizeof(InputEvent));

    ViewPort* view_port = view_port_alloc();
    view_port_draw_callback_set(view_port, draw_callback, NULL);
    view_port_input_callback_set(view_port, input_callback, event_queue);

    Gui* gui = furi_record_open(RECORD_GUI);
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);

    InputEvent event;
    bool running = true;

    // The main loop
    while(running) {
        if(furi_message_queue_get(event_queue, &event, 100) == FuriStatusOk) {
            if(event.type == InputTypePress && event.key == InputKeyBack) {
                running = false;
            }
        }
    }

    // Start cleanup
    gui_remove_view_port(gui, view_port);
    furi_record_close(RECORD_GUI);
    view_port_free(view_port);
    furi_message_queue_free(event_queue);

    return 0;
}