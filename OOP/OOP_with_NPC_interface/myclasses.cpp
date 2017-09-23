#include "myclasses.h"

using namespace std;

//Методы класса матрицы

NPC::NPC() //конструктор по умолчанию, создает "шаблонного" персонажа
{
    HealthPoints = 100;
    ManaPoints = 50;
    damage = 10.5;
    armor = 2.5;
    name = "Basic Character";
    specialization = "Warrior";
}

NPC::NPC(int HP, int MP, float DMG, float ARM, string n, int spec) //конструктор инициализации
{
    HealthPoints = HP;
    ManaPoints = MP;
    damage = DMG;
    armor = ARM;
    name = n;
    if (spec==1)
        specialization = "Warrior";
    if (spec==2)
        specialization = "Mage";
    if (spec==3)
        specialization = "Rogue";
}

NPC::NPC(const NPC &obj) //конструктор копирования
{

}

NPC::~NPC() //деструктор
{

}

void NPC::setHP(int HP) const //интеллектуальный модификатор для здоровья
{
    if (HP<0)
        HP = HP * (-1);
    HealthPoints = HP;
}

void NPC::setMP(int MP) const //интеллектуальный модификатор для маны
{
    if (MP<0)
        MP = MP * (-1);
    ManaPoints = MP;
    // damage = MP; - МОДИФИКАТОР С CONST, А ПЕРЕМЕННАЯ НЕ MUTED => ОШИБКА!!!
}

void NPC::setDamage(float DMG) //интеллектуальный модификатор для урона
{
    if (DMG<0)
        DMG = DMG * (-1);
    damage = DMG;
}

void NPC::setArmor(float ARM) //интеллектуальный модификатор для брони
{
    if (ARM<0)
        ARM = ARM * (-1);
    armor = ARM;
}

void NPC::setName(string n) //модификатор для имени
{
    name = n;
}

void NPC::setSpec(int spec)//интеллектуальный модификатор для специальности
{
    if (spec==1)
        specialization = "Warrior";
    if (spec==2)
        specialization = "Mage";
    if (spec==3)
        specialization = "Rogue";
}

int NPC::getHP() const //получение очков здоровья
{
    return HealthPoints;
}

int NPC::getMP() const //получение очков маны
{
    return ManaPoints;
}

float NPC::getDamage() const //получение наносимого урона
{
    return damage;
}

float NPC::getArmor() const //получение брони
{
    return armor;
}

string NPC::getName() const //получение имени
{
    return name;
}

string NPC::getSpec() const //получение специализации
{
    return specialization;
}

NPC NPC::operator +(NPC & npc1) //перегрузка оператора + между двумя объектами
{
    NPC tmp;

    tmp.setName(name + " + " + npc1.name);
    tmp.setArmor(armor + npc1.armor);
    tmp.setDamage(damage + npc1.damage);
    tmp.setHP(HealthPoints + npc1.HealthPoints);
    tmp.setMP(ManaPoints + npc1.ManaPoints);

    //для специализации нового объекта берется специализцаия первого в сумме объекта
    int spec;
    if (specialization == "Warrior")
        spec = 1;
    if (specialization == "Mage")
        spec = 2;
    if (specialization == "Rogue")
        spec = 3;
    tmp.setSpec(spec);

    return tmp;
}

NPC NPC::operator -(NPC & npc1) //перегрузка оператора - между двумя объектами
{
    NPC tmp;

    tmp.setName(name + " - " + npc1.name);
    tmp.setArmor(abs(armor - npc1.armor));
    tmp.setDamage(abs(damage - npc1.damage));
    tmp.setHP(fabs(HealthPoints - npc1.HealthPoints));
    tmp.setMP(fabs(ManaPoints - npc1.ManaPoints));

    //для специализации нового объекта берется специализцаия первого в сумме объекта
    int spec;
    if (specialization == "Warrior")
        spec = 1;
    if (specialization == "Mage")
        spec = 2;
    if (specialization == "Rogue")
        spec = 3;
    tmp.setSpec(spec);

    return tmp;
}

NPC operator +(NPC& npc, int x) //перегрузка оператора + между объектом и целым числом
{
    NPC tmp;

    tmp.setName(npc.getName());
    tmp.setArmor(npc.getArmor() + x);
    tmp.setDamage(npc.getDamage() + x);
    tmp.setHP(npc.getHP() + x);
    tmp.setMP(npc.getMP() + x);

    int spec;
    if (npc.getSpec() == "Warrior")
        spec = 1;
    if (npc.getSpec() == "Mage")
        spec = 2;
    if (npc.getSpec() == "Rogue")
        spec = 3;
    tmp.setSpec(spec);

    return tmp;
}

NPC operator -(NPC& npc, int x) //перегрузка оператора - между объектом и целым числом
{
    NPC tmp;

    tmp.setName(npc.getName());
    tmp.setArmor(abs(npc.getArmor() - x));
    tmp.setDamage(abs(npc.getDamage() - x));
    tmp.setHP(fabs(npc.getHP() - x));
    tmp.setMP(fabs(npc.getMP() - x));

    int spec;
    if (npc.getSpec() == "Warrior")
        spec = 1;
    if (npc.getSpec() == "Mage")
        spec = 2;
    if (npc.getSpec() == "Rogue")
        spec = 3;
    tmp.setSpec(spec);

    return tmp;
}

NPC& NPC::operator ++() //перегрузка оператора префиксный инкремент
{
    armor++; //увеличивается значение защиты
    return *this;
}

NPC NPC::operator ++(int k) //перегрузка оператора постфиксный инкремент
{
    NPC tmp(*this);
    operator++();

    return tmp;
}

NPC& NPC::operator --() //перегрузка оператора префиксный декремент
{
    armor--; //уменьшается значение защиты
    return *this;
}

NPC NPC::operator --(int k) //перегрузка оператора постфиксный декремент
{
    NPC tmp(*this);
    operator--();

    return tmp;
}

bool NPC::operator <(const NPC& npc1) //перегрузка оператора сравнения <
{
    return (HealthPoints < npc1.HealthPoints); //сравнивается здоровье
}

bool NPC::operator >(const NPC& npc1) //перегрузка оператора сравнения >
{
    return (HealthPoints > npc1.HealthPoints); //сравнивается здоровье
}

bool NPC::operator ==(const NPC& npc1) //перегрузка логического оператора ==
{
    if ((name == npc1.name) && (armor == npc1.armor) && (damage == npc1.damage) && (HealthPoints == npc1.HealthPoints) && (ManaPoints == npc1.ManaPoints)
            && (specialization == npc1.specialization)) //если все свойства равны, то объекты равны
        return true;
    else
        return false;
}

bool NPC::operator !=(const NPC& npc1) //перегрузка логического оператора !=
{
    return !(*this == npc1);
}

NPC NPC::operator ()(int a, int b, int c, int d) //перегрузка оператора () функтора
{
    NPC tmp;

    tmp.setName(name);

    //изменяются значения на велечины, которые подаются в функтор
    tmp.setHP(HealthPoints + a);
    tmp.setMP(ManaPoints + b);
    tmp.setDamage(damage + c);
    tmp.setArmor(armor + d);

    int spec;
    if (specialization == "Warrior")
        spec = 1;
    if (specialization == "Mage")
        spec = 2;
    if (specialization == "Rogue")
        spec = 3;
    tmp.setSpec(spec);

    return tmp;

}

NPC& NPC::operator =(int x) //перегрузка оператора = присваивания
{
    //численные свойства становятся равными переданной величине
    HealthPoints = x;
    ManaPoints = x;
    armor = x;
    damage = x;

    return *this;
}

NPC::operator bool() const //перегрузка оператора приведение типов, в булевую переменную
{
    if (ManaPoints != 0 && armor != 0 && damage != 0) //если численные переменные не равны нулю, то объект преобразуется в true
        return true;
    return false;
}

NPC NPC::operator <<(int num) //перегрузка побитового оператора << сдвиг влево
{
    NPC tmp;

    tmp.setName(name);

    //влево сдвигаются свойства типа int
    tmp.setHP(HealthPoints << num);
    tmp.setMP(ManaPoints << num);

    tmp.setDamage(damage);
    tmp.setArmor(armor);

    int spec;
    if (specialization == "Warrior")
        spec = 1;
    if (specialization == "Mage")
        spec = 2;
    if (specialization == "Rogue")
        spec = 3;
    tmp.setSpec(spec);

    return tmp;
}

NPC NPC::operator >>(int num) //перегрузка побитового оператора >> сдвиг вправо
{
    NPC tmp;

    tmp.setName(name);

    //вправо сдвигаются свойства типа int
    tmp.setHP(HealthPoints >> num);
    tmp.setMP(ManaPoints >> num);

    tmp.setDamage(damage);
    tmp.setArmor(armor);

    int spec;
    if (specialization == "Warrior")
        spec = 1;
    if (specialization == "Mage")
        spec = 2;
    if (specialization == "Rogue")
        spec = 3;
    tmp.setSpec(spec);

    return tmp;
}

//функция вывода информации об НПЦ в QString
string NPC::show()
{
    string result;

    //Их суммирование
    result.append(name);
    result.append(" the ");
    result.append(specialization);
    result.append(" - ");
    result.append(to_string(HealthPoints));
    result.append(" HP, ");
    result.append(to_string(ManaPoints));
    result.append(" MP, ");
    result.append(to_string(damage));
    result.append(" DMG, ");
    result.append(to_string(armor));
    result.append(" ARM\n");

    return result;
}

string NPC::fshow()
{
    string result;

    //Их суммирование
    result.append(name);
    result.append("\n");
    result.append(specialization);
    result.append("\n");
    result.append(to_string(HealthPoints));
    result.append("\n");
    result.append(to_string(ManaPoints));
    result.append("\n");
    result.append(to_string(damage));
    result.append("\n");
    result.append(to_string(armor));
    result.append("\n\n");

    return result;
}


//Методы класса монстра

monster::monster() : NPC(50, 0, 5.1, 1.5, "Bunny", 2) //конструктор по умолчанию
{
    agression = 0;
}
monster::monster(int HP, int MP, float DMG, float ARM, int agro, string n, int spec) //конструктор инициализации
    : NPC(HP, MP, DMG, ARM, n, spec)
{
    agression = agro;
}

monster::monster(const monster &obj) //конструктор копирования
{

}

monster::~monster() //деструктор
{

}

void monster::setAgression(int agr)
{
    if (agr < 0)
        agr = agr * (-1);
    agression = agr;
}

int monster::getAgression() const
{
    return agression;
}

string monster::show()
{
    string result;

    //Их суммирование
    result.append(getName());
    result.append(" the ");
    result.append(getSpec());
    result.append(" - ");
    result.append(to_string(getHP()));
    result.append(" HP, ");
    result.append(to_string(getMP()));
    result.append(" MP, ");
    result.append(to_string(getDamage()));
    result.append(" DMG, ");
    result.append(to_string(getArmor()));
    result.append(" ARM, agro = ");
    result.append(to_string(agression));
    result.append("\n");

    return result;
}

string monster::fshow()
{
    string result;

    //Их суммирование
    result.append(getName());
    result.append("\n");
    result.append(getSpec());
    result.append("\n");
    result.append(to_string(getHP()));
    result.append("\n");
    result.append(to_string(getMP()));
    result.append("\n");
    result.append(to_string(getDamage()));
    result.append("\n");
    result.append(to_string(getArmor()));
    result.append("\n");
    result.append(to_string(agression));
    result.append("\n\n");

    return result;
}
