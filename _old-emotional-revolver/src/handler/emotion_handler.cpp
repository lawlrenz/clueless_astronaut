#include "emotion_handler.h"


EmotionHandler::EmotionHandler(){
  m_happyness = 0.0;
  m_carelessness = 0.0;
  m_emo_state = 0;
  m_player_unit = GameRegistry::getInstance()->getLevelHandler()->getPlayerEntity();
}


// alter emotionvalues (after killing good people and stuff, time,..)
void EmotionHandler::alterEmotion(double alter_value_happyness, double alter_value_carelessness){
  m_happyness += alter_value_happyness;
  m_carelessness += alter_value_carelessness;
}

// "signal" Weapon for different Weapon behavior
void EmotionHandler::sigPlayerUnit(){
  m_player_unit->changeMode(m_emo_state);
  std::cout << "New State:" << m_emo_state << "\n";
}

// returns Emotion/Mode
int EmotionHandler::getEmotion(){
  /*
  MODES (return values):
  Normal: 0
  Schrot: 1
  Autofire: 2
  Chargedshots: 3
  Sniper: 4
  Slowmotion: 5
  SuperSchnellesSchießen: 6
  5 Sekunden lang unkontrolliert Schießen:  7
  Vor Trauer sterben: 8
  */
  double winkel;
  if(m_happyness == 0){
    winkel = PI/2;
  }
  else{
    winkel = atan(m_carelessness/m_happyness);
  }
  double value = sqrt(m_happyness * m_happyness + m_carelessness * m_carelessness);
  int tmp = winkel/(PI/6.0);

  if(value < 25){
    return 0;
  }
  if(tmp == 0){
    if(value < 50){
      return 3;
    }
    else if(value < 75){
      return 1;
    }
  }
  else if(tmp == 1){
    if(value < 50){
      return 4;
    }
    else if(value < 75){
      return 5;
    }
  }
  else if(tmp == 2){
    if(value < 50){
      return 6;
    }
    else if(value < 75){
      return 2;
    }
  }
  if(m_happyness >= 100){
    return 8;
  }
  return 7;

}

// observe emotions
void EmotionHandler::emotionUpdate(){

  double carelessness_dezimizer = 0.10;
  double happyness_dezimizer = 0.15;
  if(m_happyness < 100){
    alterEmotion(happyness_dezimizer, 0);
  }
  else{
    m_happyness = 50;
  }
  if(m_carelessness < 100){
    alterEmotion(0, carelessness_dezimizer);
  }
  else{
    m_carelessness = 50;
  }
  if(getEmotion() != m_emo_state){
    m_emo_state = getEmotion();
    sigPlayerUnit();
    if(m_emo_state == 8) {
      std::cout << "Suicide. \n";
    }
  }
  //std::cout << "Happyness: " << m_happyness << "\n";
  //std::cout << "Carlessness: " << m_carelessness << "\n";
}
