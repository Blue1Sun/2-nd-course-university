#include "myclasses.h"

using namespace std;

//������ ������ �������

NPC::NPC() //����������� �� ���������, ������� "����������" ���������
{
    HealthPoints = 100;
    ManaPoints = 50;
    damage = 10.5;
    armor = 2.5;
    name = "Basic Character";
    specialization = "Warrior";
}

NPC::NPC(int HP, int MP, float DMG, float ARM, string n, int spec) //����������� �������������
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

NPC::NPC(const NPC &obj) //����������� �����������
{

}

NPC::~NPC() //����������
{

}

void NPC::setHP(int HP) const //���������������� ����������� ��� ��������
{
    if (HP<0)
        HP = HP * (-1);
    HealthPoints = HP;
}

void NPC::setMP(int MP) const //���������������� ����������� ��� ����
{
    if (MP<0)
        MP = MP * (-1);
    ManaPoints = MP;
    // damage = MP; - ����������� � CONST, � ���������� �� MUTED => ������!!!
}

void NPC::setDamage(float DMG) //���������������� ����������� ��� �����
{
    if (DMG<0)
        DMG = DMG * (-1);
    damage = DMG;
}

void NPC::setArmor(float ARM) //���������������� ����������� ��� �����
{
    if (ARM<0)
        ARM = ARM * (-1);
    armor = ARM;
}

void NPC::setName(string n) //����������� ��� �����
{
    name = n;
}

void NPC::setSpec(int spec)//���������������� ����������� ��� �������������
{
    if (spec==1)
        specialization = "Warrior";
    if (spec==2)
        specialization = "Mage";
    if (spec==3)
        specialization = "Rogue";
}

int NPC::getHP() const //��������� ����� ��������
{
    return HealthPoints;
}

int NPC::getMP() const //��������� ����� ����
{
    return ManaPoints;
}

float NPC::getDamage() const //��������� ���������� �����
{
    return damage;
}

float NPC::getArmor() const //��������� �����
{
    return armor;
}

string NPC::getName() const //��������� �����
{
    return name;
}

string NPC::getSpec() const //��������� �������������
{
    return specialization;
}

NPC NPC::operator +(NPC & npc1) //���������� ��������� + ����� ����� ���������
{
    NPC tmp;

    tmp.setName(name + " + " + npc1.name);
    tmp.setArmor(armor + npc1.armor);
    tmp.setDamage(damage + npc1.damage);
    tmp.setHP(HealthPoints + npc1.HealthPoints);
    tmp.setMP(ManaPoints + npc1.ManaPoints);

    //��� ������������� ������ ������� ������� ������������� ������� � ����� �������
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

NPC NPC::operator -(NPC & npc1) //���������� ��������� - ����� ����� ���������
{
    NPC tmp;

    tmp.setName(name + " - " + npc1.name);
    tmp.setArmor(abs(armor - npc1.armor));
    tmp.setDamage(abs(damage - npc1.damage));
    tmp.setHP(fabs(HealthPoints - npc1.HealthPoints));
    tmp.setMP(fabs(ManaPoints - npc1.ManaPoints));

    //��� ������������� ������ ������� ������� ������������� ������� � ����� �������
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

NPC operator +(NPC& npc, int x) //���������� ��������� + ����� �������� � ����� ������
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

NPC operator -(NPC& npc, int x) //���������� ��������� - ����� �������� � ����� ������
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

NPC& NPC::operator ++() //���������� ��������� ���������� ���������
{
    armor++; //������������� �������� ������
    return *this;
}

NPC NPC::operator ++(int k) //���������� ��������� ����������� ���������
{
    NPC tmp(*this);
    operator++();

    return tmp;
}

NPC& NPC::operator --() //���������� ��������� ���������� ���������
{
    armor--; //����������� �������� ������
    return *this;
}

NPC NPC::operator --(int k) //���������� ��������� ����������� ���������
{
    NPC tmp(*this);
    operator--();

    return tmp;
}

bool NPC::operator <(const NPC& npc1) //���������� ��������� ��������� <
{
    return (HealthPoints < npc1.HealthPoints); //������������ ��������
}

bool NPC::operator >(const NPC& npc1) //���������� ��������� ��������� >
{
    return (HealthPoints > npc1.HealthPoints); //������������ ��������
}

bool NPC::operator ==(const NPC& npc1) //���������� ����������� ��������� ==
{
    if ((name == npc1.name) && (armor == npc1.armor) && (damage == npc1.damage) && (HealthPoints == npc1.HealthPoints) && (ManaPoints == npc1.ManaPoints)
            && (specialization == npc1.specialization)) //���� ��� �������� �����, �� ������� �����
        return true;
    else
        return false;
}

bool NPC::operator !=(const NPC& npc1) //���������� ����������� ��������� !=
{
    return !(*this == npc1);
}

NPC NPC::operator ()(int a, int b, int c, int d) //���������� ��������� () ��������
{
    NPC tmp;

    tmp.setName(name);

    //���������� �������� �� ��������, ������� �������� � �������
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

NPC& NPC::operator =(int x) //���������� ��������� = ������������
{
    //��������� �������� ���������� ������� ���������� ��������
    HealthPoints = x;
    ManaPoints = x;
    armor = x;
    damage = x;

    return *this;
}

NPC::operator bool() const //���������� ��������� ���������� �����, � ������� ����������
{
    if (ManaPoints != 0 && armor != 0 && damage != 0) //���� ��������� ���������� �� ����� ����, �� ������ ������������� � true
        return true;
    return false;
}

NPC NPC::operator <<(int num) //���������� ���������� ��������� << ����� �����
{
    NPC tmp;

    tmp.setName(name);

    //����� ���������� �������� ���� int
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

NPC NPC::operator >>(int num) //���������� ���������� ��������� >> ����� ������
{
    NPC tmp;

    tmp.setName(name);

    //������ ���������� �������� ���� int
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

//������� ������ ���������� �� ��� � QString
string NPC::show()
{
    string result;

    //�� ������������
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

    //�� ������������
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


//������ ������ �������

monster::monster() : NPC(50, 0, 5.1, 1.5, "Bunny", 2) //����������� �� ���������
{
    agression = 0;
}
monster::monster(int HP, int MP, float DMG, float ARM, int agro, string n, int spec) //����������� �������������
    : NPC(HP, MP, DMG, ARM, n, spec)
{
    agression = agro;
}

monster::monster(const monster &obj) //����������� �����������
{

}

monster::~monster() //����������
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

    //�� ������������
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

    //�� ������������
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
