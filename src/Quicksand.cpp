// #include "../include/Quicksand.h"
// #include "../include/Character.h"
// #include <iostream>
//
// Quicksand::Quicksand(const int escape, const int total_damage, const std::string& name, const int pos_x, const int pos_y, const int damage_per_second, bool active)
//     : Obstacle(name, total_damage, pos_x, pos_y, active), escape_time(escape), damage_in_time(damage_per_second),
//       duration(escape), initialDuration(escape) {}
//
// Quicksand::Quicksand(): escape_time(0), damage_in_time(0), duration(0), initialDuration(0) {
// }
//
// void Quicksand::activate(Character& target) {
//     (void) target;
//     active = true;
// }
//
// int Quicksand::calculateDamage() const {
//     if (duration > escape_time/2)
//         return damage_in_time;
//     if (duration > 1)
//         return damage_in_time * 2;
//     return 0;
// }
//
// void Quicksand::applyDamage(Character& target) {
//     int damage = calculateDamage();
//     if (damage > 0) {
//         target.receiveDamage(damage);
//     } else {
//         deactivate();
//         return;
//     }
//     duration --;
// }
//
// int Quicksand::getBaseDamage() const {
//     return damage_in_time * escape_time;
// }
//
// void Quicksand::deactivate() {
//     active = false;
// }
//
// // void Quicksand::tick(Character& target) {
// //     if (active) {
// //         applyDamage(target);
// //     }
// // }
//
// // void Quicksand::reset() {
// //     duration = initialDuration;
// //     active = false;
// // }
//
// Quicksand::~Quicksand() = default;
