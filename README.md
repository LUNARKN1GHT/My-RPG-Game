# C++ RPG 游戏系统

## 项目设计类图

```mermaid
classDiagram
%% Character 类及子类
  class Character {
    -string name
    -int level
    -int hp
    -int mp
    +void attack(Character &target)
    +void takeDamage(int dmg)
    +void useSkill(int skillIndex, Character &target)
    +void addSkill(Skill* skill)
  }

%% 子类
  class Warrior {
    +void heavyAttack(CHaracter &target)
  }
  class Mage {
    +void castSpell(Character &target)
  }
  class Archer {
    +void rangedAttack(Character &target)
  }

  Character <|-- Warrior
  Character <|-- Mage
  Character <|-- Archer
%% Skill 类
  class Skill {
    -string skillName
    -int power
    -int mpCost
    +void use(Character &user, Character &target)
  }

  Character "1" --> "*" Skill: has
%% Item & Inventory
  class Item {
    -string itemName
    -string description
    +void use(Character &user)
  }

  class Inventory {
    -list<Item*> items
    +void addItem(Item* item)
    +void removeItem(Item* item)
    +void useItem(int index, Character &user)
  }

  Character "1" --> "1" Inventory: owns
  Inventory "1" --> "*" Item: contains
%% Battle 系统
  class Battle {
    -Character* player
    -Character* enemy
    +void startBattle()
    +void playerTurn()
    +void enemyTurn()
    +bool isBattleOver()
  }

  Battle "1" --> "1" Character: player
  Battle "1" --> "1" Character: enemy
%% 可选扩展类
  class Potion {
    -int healAmount
    +void use(Character &user)
  }

  Potion --|> Item
```

## 目标

练习 C++ 面向对象，模块化设计，以及 Git 分支管理。

## 功能规划

- Character 基类 + 子类 (Warrior, Mage, Archer)
- Skill 类组合到 Character
- 简单战斗逻辑

## 角色设计

|  角色职业   | 攻击力 | 最大蓝量 | 防御力 | 最大生命值 |
|:-------:|:---:|:----:|:---:|:-----:|
| Warrior | 15  |  20  | 15  |  50   |
|  Mage   | 10  |  50  |  5  |  30   |
| Archer  | 10  |  20  | 10  |  40   |

## 更新日志

### v0.6 

#### v0.6 新增内容

- 将角色技能信息打印与角色基本信息打印分离。
- 提供外部获取角色技能组接口 `getSkills()`
- 新增类 `DamageType` 用于将伤害类型进行区分。包括物理伤害、魔法伤害和真实伤害。

#### v0.6 修改内容

- 将角色抗性分为物理和魔法，与上述伤害类型对应。

### v0.5.1 项目整理

#### v0.5.1 新增内容

- 增加项目 UML 绘图，便于理清项目结构

#### v0.5.1 修改内容

- 将项目迁移到 `CLion` 上继续开发
- 对项目代码进行格式化处理，并按照现代C++开发的要求进行了相应的标注

### v0.5 技能系统优化

#### v0.5 新增内容

- 增加技能蓝量消耗
- 增加技能冷却时间
- 在 `Character` 中增加技能获取接口

#### v0.5 修改内容

- 将普通攻击也设置为技能类
- 在职业继承类中也将普通攻击改为技能

#### v0.5 修正

- 准备将项目迁移到 CLion 中继续开发

### v0.4 技能系统

#### v0.4 新增内容

- 引入 `Skills` 技能系统
    - 设计并实现抽象基类
    - 支持技能名称和描述信息展示
- `Character` 中加入技能管理
- 实现首个技能示例：`Fireball`

### v0.3 战斗系统

#### v0.3 新增内容

- 实现基础战斗系统 `Battle`
- 支持角色之间回合制交互
- 支持敌人列表管理

### v0.2 角色抽象基类

#### v0.2 新增内容

- 抽象基类 `Character`
- 派生职业：
    - `Warrior`
    - `Mage`
    - `Archer`
- 使用虚函数实现多态攻击行为

### v0.1 初始化

- 构建 Git 仓库
- 配置 CMake
- 创建基础目录结构
- 配置好编译环境

### RoadMap

- [x] 将 `BasicAttack` 重构为 skill
- [x] skill 消耗 Mana
- [x] skill 冷却时间
- [ ] 玩家技能选择 UI
- [ ] AI 使用技能决策
- [x] 分离物抗和魔抗
- [x] 区分技能的伤害类型
