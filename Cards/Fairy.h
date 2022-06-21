#ifndef HW4_FAIRY_H
#define HW4_FAIRY_H
#include "Appliance.h"
//#include <iostream>
//#include <memory>
//#include "../Players/Player.h"


class Fairy : public Appliance
{
public:
    /*
  * C'tor of Fairy class
  *Default
  *@return A new instance of Fairy.
  */
    explicit Fairy() = default;
    /*
   * D'tor of Fairy class
   *
   *Default
   * destroys Fairy
   */
    ~Fairy()override = default;
    /*
*  Creates and returns a unique pointer to new instance of Fairy
*  @return unique pointer
*/
    static std::unique_ptr<Fairy> createFairy();
    /*
*  Applies each Cards effect on Player
*  @param player- player who turn it is on the card
*  @return false always
*/
    bool applyEncounter(Player& player) override;
    /*
*  Gives us the Type of the card
*  @return string "Fairy"
*/
    std::string getType() const override;


private:
    static const int HEALTH_HEAL = 10;
    const std::string type = "Fairy";

};


#endif //HW4_FAIRY_H
