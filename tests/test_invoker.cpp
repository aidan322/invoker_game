#include <gtest/gtest.h>
#include "../include/spell.hpp"
#include "../include/invoker.hpp"
#include "../include/rank_mode.hpp"
#include "../include/ai_mode.hpp"
#include "../include/player.hpp"
#include "../include/card.hpp"

TEST(SpellTest, MatchesComboIgnoresCaseAndSpaces) {
    Spell s("cold_snap", "Q Q Q");
    EXPECT_TRUE(s.matchesCombo("qqq"));
    EXPECT_TRUE(s.matchesCombo("Q Q Q"));
    EXPECT_FALSE(s.matchesCombo(" q  Q w e   "));
    EXPECT_FALSE(s.matchesCombo("QQE"));
}


TEST(InvokerTest, CanFindComboByName) {
    Invoker inv;
    inv.addSpell(std::make_unique<Spell>("tornado", "W W Q"));
    inv.addSpell(std::make_unique<Spell>("sun_strike", "E E E"));

    EXPECT_EQ(inv.getComboByName("tornado"), "WWQ");
    EXPECT_TRUE(inv.validateComboByName("sun_strike", "e e e"));
    EXPECT_FALSE(inv.validateComboByName("tornado", "qqq"));
}


TEST(PlayerTest, FieldInitialization) {
    Player p(1);
    EXPECT_FALSE(p.isFieldFull());
    EXPECT_EQ(p.getCardType(0, 0), "EmptySlot");
}


TEST(PlayerTest, MoveCardToFieldWorks) {
    Player p(1);
    auto c = std::make_unique<CharacterCard>("Invoker", 100, 20, 0, 5);
    p.moveCardToField(std::move(c), 0, 0);
    EXPECT_EQ(p.getCardType(0, 0), "Invoker");
}


TEST(RankModeTest, RanksOutputTimeThresholds) {
    double time = 12.0;
    EXPECT_TRUE(time > 10.0 && time <= 15.0);
}
