#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_RED_CAPOTE) == EFFECT_MINIMIZE);
}

SINGLE_BATTLE_TEST("Red Capote boosts evasion by two stages.")
{

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RED_CAPOTE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RED_CAPOTE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_EVASION], DEFAULT_STAT_STAGE + 2);
    }
}
