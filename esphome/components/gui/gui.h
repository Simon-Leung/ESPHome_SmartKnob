#pragma once

#include "esphome.h"
#include "gui_objects.h"
#include "lvgl.h"

namespace esphome {

// forward declare Display
namespace display {
class Display;
}  // namespace display
// forward declare binary_sensor
namespace binary_sensor {
class BinarySensor;
}  // namespace binary_sensor
// forward declare rotary_encoder
namespace rotary_encoder {
class RotaryEncoderSensor;
}  // namespace rotary_encoder

namespace gui {
#if LV_COLOR_DEPTH == 8
static const display::ColorBitness LV_BITNESS = display::ColorBitness::COLOR_BITNESS_332;
#elif LV_COLOR_DEPTH == 32
static const display::ColorBitness LV_BITNESS = display::ColorBitness::COLOR_BITNESS_888;
#else
static const display::ColorBitness LV_BITNESS = display::ColorBitness::COLOR_BITNESS_565;
#endif
#define ECO_O(y) (y>0)? -1:1
#define ECO_STEP(x) x? ECO_O(x):0
using namespace display;
using namespace rotary_encoder;
using namespace binary_sensor;

class GuiComponent : public Component {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
  float get_setup_priority() const override {
    return setup_priority::PROCESSOR;
  }
#if LV_USE_LOG
  static void lv_esp_log(const char *buf);
#endif

  void set_display(Display *display) { this->display_ = display; }
  static void refresh(lv_disp_drv_t *disp_drv, const lv_area_t *area,
                          lv_color_t *buf);
#ifdef GUI_USE_ENCODER
  void set_encoder(RotaryEncoderSensor *enc) {this->enc_ = enc; }
  static void enc_read(struct _lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
  void set_pushbutton(BinarySensor *btn) {this->btn_ = btn; }
#endif

 protected:
  void refresh_internal_(lv_disp_drv_t *disp_drv, const lv_area_t *area,
                    lv_color_t *buf);

  Display *display_{nullptr};

  lv_disp_t *lv_disp_{nullptr};
  lv_disp_drv_t disp_drv_{};
  lv_disp_draw_buf_t draw_buf_{};
  lv_disp_rot_t get_lv_rotation();

#ifdef GUI_USE_ENCODER
  RotaryEncoderSensor *enc_{nullptr};
  lv_indev_drv_t enc_drv_{};
  lv_indev_t *lv_enc_{nullptr};
  BinarySensor *btn_{nullptr};
#endif

 private:
  HighFrequencyLoopRequester high_freq_;
  uint32_t last_loop_{0};
};

}  // namespace gui
}  // namespace esphome