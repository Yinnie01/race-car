#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structures section
struct Race {
  int numberOfLaps;
  int currentLap;
  int firstPlaceLapTime;
  int secondPlaceLapTime;
  char* firstPlaceDriverName;
  char* firstPlaceRaceCarColor;
  char* secondPlaceDriverName;
  char* secondPlaceRaceCarColor;
};

struct RaceCar {
  char* driverName;
  char* raceCarColor;
  int totalLapTime;
};
// Print functions section
void printIntro(void) {
  printf("Welcome to our main event digital race fans!\nI hope everyone has their snacks because we are about to begin!\n");
}
void printCountDown(void) {
  printf("Racers Ready! In...\n5\n4\n3\n2\n1\nRace!\n\n");
}
void printFirstPlaceAfterLap(struct Race race) {
  printf("After lap number %d \nFirst Place Is: %s in the %s race car! With a total lap time of %d minutes! \n", race.currentLap, race.firstPlaceDriverName, race.firstPlaceRaceCarColor, race.firstPlaceLapTime);
}

void printSecondRunnerUp(struct Race race) {
  printf("The second runner up is: %s in the %s race car with a total lap time of %d minutes! \n\n", race.secondPlaceDriverName, race.secondPlaceRaceCarColor, race.secondPlaceLapTime);
}
void printCongratulation(struct Race race) {
  printf("Let's all congratulate %s in the %s race car for an amazing performance. \nIt truly was a great race and everybody have a good night.\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}
// Logic functions section
int calculateTimeToCompleteLap(void){
  int speed = rand() % 3 + 1;
  int acceleration = rand() % 3 + 1;
  int nerves = rand() % 3 + 1;
  return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar* raceCar){
  raceCar->totalLapTime += calculateTimeToCompleteLap(); 
}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  if ((*raceCar1).totalLapTime <= (*raceCar2).totalLapTime) {
// update first place driver name, car colour and laptime
    race->firstPlaceDriverName = raceCar1->driverName;
    race->firstPlaceRaceCarColor = raceCar1->raceCarColor;
    race->firstPlaceLapTime = raceCar1->totalLapTime;
// update second place driver name, car colour and laptime
    race->secondPlaceDriverName = raceCar2->driverName;
    race->secondPlaceRaceCarColor = raceCar2->raceCarColor;
    race->secondPlaceLapTime = raceCar2->totalLapTime;
  } else {
// update first place driver name, car colour and laptime
    race->firstPlaceDriverName = raceCar2->driverName;
    race->firstPlaceRaceCarColor = raceCar2->raceCarColor;
    race->firstPlaceLapTime = raceCar2->totalLapTime;
// update second place driver name, car colour and laptime
    race->secondPlaceDriverName = raceCar1->driverName;
    race->secondPlaceRaceCarColor = raceCar1->raceCarColor;
    race->secondPlaceLapTime = raceCar1->totalLapTime;
  }
}

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  struct Race race = {5, 1, 0, 0, "", "", "", ""};
  struct Race* racePtr = &race;
  for (int i = 1; i <= race.numberOfLaps; i++){
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
    printSecondRunnerUp(race);
    (*racePtr).currentLap = i + 1;
  }
  printCongratulation(race);
}

int main() {
	srand(time(NULL));
  printIntro();
  printCountDown();
  struct RaceCar raceCar1 = {"Yinnie", "Yellow", 0};
  struct RaceCar raceCar2 = {"Durling", "Red", 0};
  startRace(&raceCar1, &raceCar2);
};
