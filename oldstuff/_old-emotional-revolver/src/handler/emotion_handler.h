#ifndef EMOTION_HANDLER_H
#define EMOTION_HANDLER_H

#include <time.h>
#include <iostream>

#include <complex>
#include <math.h>
#define PI 3.14159265

#include "entity/unit_entity.h"
#include "handler/level_handler.h"
#include "registry/game_registry.h"

class EmotionHandler
{
public:
  EmotionHandler();
  void alterEmotion(double alter_value_happyness, double alter_value_carelessness);
  void emotionUpdate();
private:
  void sigPlayerUnit();
  int getEmotion();
  UnitEntity *m_player_unit;
  double m_happyness;
  double m_carelessness;
  int m_emo_state;
};

#endif
