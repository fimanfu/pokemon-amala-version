#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_CHAOTIC_WILL) == EFFECT_OHKO);
}

SINGLE_BATTLE_TEST("Chaotic Will faints target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET); // 1.
        OPPONENT(SPECIES_WOBBUFFET); // 2.
    } WHEN {
        TURN { MOVE(player, MOVE_CHAOTIC_WILL); } // 3.
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHAOTIC_WILL, player);
        MESSAGE("The opposing Wobbuffet fainted!"); // 4
    }
}

DOUBLE_BATTLE_TEST("Chaotic Will will faint both targets")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET); 
        PLAYER(SPECIES_WOBBUFFET); 
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CHAOTIC_WILL); } // 3.
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHAOTIC_WILL, playerLeft);
        MESSAGE("The opposing Wobbuffet fainted!"); // 4
        MESSAGE("The opposing Wobbuffet fainted!");
    }
}
