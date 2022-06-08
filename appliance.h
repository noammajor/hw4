class Appliance
{
    Appliance()=default;

    ~Appliance()=default;

    virtual void applyEncounter(Player& player);

protected:
    int static const m_hpEffect=10;

}
