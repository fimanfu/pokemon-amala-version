#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Magatama inherits Mold Breaker's effect and ignores Ice Scales", s16 damage)
{
    u16 ability;
    PARAMETRIZE { ability = ABILITY_SHADOW_TAG; }
    PARAMETRIZE { ability = ABILITY_MAGATAMA; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_PSYCHIC) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_FROSMOTH) { Ability(ABILITY_ICE_SCALES); }
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHIC); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, UQ_4_12(0.5), results[0].damage);
    }
}