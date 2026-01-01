//
// Created by LEE32 on 2026/1/1.
//

#include "../include/item/Item.h"

/**
 *
 * @param name 物品名称
 * @param description 物品描述
 * @param targetType 物品适用对象标注
 */
Item::Item(const std::string &name, const std::string &description, const TargetType targetType)
    : name_(name), descriptions_(description), targetType_(targetType){
}
