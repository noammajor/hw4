class Appliance
{
    Appliance()=default;

    ~Appliance()=default;

protected:
    int static const m_hpEffect=10;
    virtual void applyEncounter(Player& player);
}
