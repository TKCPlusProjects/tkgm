#ifndef tkgm_set_form_video_hpp
#define tkgm_set_form_video_hpp

#include <tkgm/tkgm_set_form.hpp>

namespace tkht {
namespace tkgm {
class SetFormVideo : public SetForm {
public:
  shared_ptr<SliderIntItem>window_width = make_shared<SliderIntItem>("window_width", "Window Width", 0, 2160); // 屏幕宽度
  shared_ptr<SliderIntItem>window_height = make_shared<SliderIntItem>("window_height", "Window Height", 0, 1440); // 屏幕高度
  shared_ptr<SliderFloatItem> hertz = make_shared<SliderFloatItem>("hertz", "Hertz", 30.0f, 120.0f); // 刷新率
  shared_ptr<SliderIntItem>velocity_iterations = make_shared<SliderIntItem>("velocity_iterations", "Velocity Iterations", 0, 10); // 物理模拟中执行速度迭代的次数
  shared_ptr<SliderIntItem>position_iterations = make_shared<SliderIntItem>("position_iterations", "Position Iterations", 0, 10); // 物理模拟中执行位置迭代的次数
  shared_ptr<CheckboxItem>draw_shapes = make_shared<CheckboxItem>("draw_shapes", "Draw Shapes"); // 绘制形状
  shared_ptr<CheckboxItem>draw_joints = make_shared<CheckboxItem>("draw_joints", "Draw Joints"); // 绘制关节
  shared_ptr<CheckboxItem>draw_aabbs = make_shared<CheckboxItem>("draw_aabbs", "Draw Aabbs");   // 绘制轮廓
  shared_ptr<CheckboxItem>draw_contactpoints = make_shared<CheckboxItem>("draw_contactpoints", "Draw Contactpoints"); // 物体之间的接触点的位置
  shared_ptr<CheckboxItem>draw_contactnormals = make_shared<CheckboxItem>("draw_contactnormals", "Draw Contactnormals"); // 物体之间的接触法线（即碰撞面的方向）
  shared_ptr<CheckboxItem>draw_contactimpulse = make_shared<CheckboxItem>("draw_contactimpulse", "Draw Contactimpulse"); // 物体之间的接触冲量（即碰撞力的大小和方向）
  shared_ptr<CheckboxItem>draw_frictionimpulse = make_shared<CheckboxItem>("draw_frictionimpulse", "Draw Frictionimpulse"); // 物体之间的摩擦力冲量（即摩擦力的大小和方向）
  shared_ptr<CheckboxItem>draw_coms = make_shared<CheckboxItem>("draw_coms", "Draw Coms"); // 绘制物体的质心位置。
  shared_ptr<CheckboxItem>draw_stats = make_shared<CheckboxItem>("draw_stats", "Draw Stats"); // 输出物理模拟的统计信息（如 FPS、时间步长度等）
  shared_ptr<CheckboxItem>draw_profile = make_shared<CheckboxItem>("draw_profile", "Draw Profile"); // 输出物理模拟的性能分析数据
  shared_ptr<CheckboxItem>enable_warmstarting = make_shared<CheckboxItem>("enable_warmstarting", "Enable Warmstarting"); // 预热，即在每个时间步中使用上一个时间步的解作为初始值进行迭代优化
  shared_ptr<CheckboxItem>enable_substepping = make_shared<CheckboxItem>("enable_substepping", "Enable Substepping"); // 子步模拟，即将每个时间步细分为多个较小的时间步以提高模拟的准确性
  shared_ptr<CheckboxItem>enable_continuous = make_shared<CheckboxItem>("enable_continuous", "Enable Continuous"); // 连续碰撞检测，即在物体高速运动时更准确地检测碰撞
  shared_ptr<CheckboxItem>enable_sleep = make_shared<CheckboxItem>("enable_sleep", "Enable Sleep"); // 休眠机制，即当物体静止时让其进入睡眠状态以减少计算量

  SetFormVideo() : SetForm("Video", "video.form") {}

  void SetupMap() override;
  void SetupDefault() override;
};
} // namespace tkgm
} // namespace tkht

#endif /* tkgm_set_form_video_hpp */
