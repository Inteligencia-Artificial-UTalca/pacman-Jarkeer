#ifndef UTILITYGHOSTCONTROLLER_H_
#define UTILITYGHOSTCONTROLLER_H_
 
#include "Controller.h"
#include <cmath>

class UtilityGhostController : public Controller
{
    std::pair<int,int> territory;

    Move getClosestMove (const GameState& game, std::pair<int,int> target) const;
    Move getFarthestMove(const GameState& game, std::pair<int,int> target) const;
    float distTo(const GameState& game, std::pair<int,int> target) const;

    
    std::pair<int,int> predictPacman(const GameState& game, int steps) const;

    float utilityFlee     (const GameState& game) const;
    float utilityIntercept(const GameState& game) const;
    float utilityPatrol   (const GameState& game) const;
    float utilityChase    (const GameState& game) const;
 
public:
    UtilityGhostController(std::shared_ptr<Character> character);
    virtual ~UtilityGhostController();
    virtual Move getMove(const GameState& game) override;
};



#endif