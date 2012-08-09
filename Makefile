# Creates test program for the TicTacToe game
# file:Makefile

# When running this test, be sure to include ${BASE_PATH}/lib in the
# environment variable LD_LIBRARY_PATH

#CPPUNIT_PATH=${BASE_PATH} 

CFLAGS?= -Wall 
LFLAGS?= 

TESTAPP = ttttest
APP = ttt
MAINOBJ = ttt.o
OBJS =  Mapper.o Game.o FindWinner.o Player.o View.o RuleFactory.o Rules.o Controller.o StepFactory.o Steps.o
TESTOBJS = Main.o MapTest.o GameTest.o FindWinnerTest.o ViewTest.o PlayerTest.o RuleTest.o ControllerTest.o StepTest.o

LIBS = -lstdc++ -ldl 

# don't want to include cppunit in the finished application
TESTLIBS = -lcppunit

all: check $(APP)

$(TESTAPP): $(OBJS) $(TESTOBJS)
	g++ -o $(TESTAPP) $(OBJS) $(TESTOBJS) $(LFLAGS) $(LIBS) $(TESTLIBS)

$(APP): $(OBJS) $(MAINOBJ)
	g++ -o $(APP) $(OBJS) $(MAINOBJ) $(LFLAGS) $(LIBS)

.cpp.o:
	g++ -c $(CFLAGS) $<

ttt.o: ttt.cpp $(OBJS)
Mapper.o: Mapper.cpp Mapper.h
Game.o: Game.cpp Game.h
FindWinner.o: FindWinner.cpp FindWinner.h
Player.o: Player.cpp Player.h
View.o: View.cpp View.h
RuleFactory.o: RuleFactory.cpp RuleFactory.h Rules.h
Rules.o: Rules.cpp Rules.h Rule.h
Controller.o: Controller.cpp Controller.h
StepFactory.o: StepFactory.cpp StepFactory.h Steps.h
Steps.o: Steps.cpp Steps.h Step.h

MapTest.o: MapTest.cpp MapTest.h Mapper.o
GameTest.o: GameTest.cpp GameTest.h Game.o
FindWinnerTest.o: FindWinnerTest.cpp FindWinnerTest.h FindWinner.o
PlayerTest.o: PlayerTest.cpp PlayerTest.h Player.o
ViewTest.o: ViewTest.cpp ViewTest.h View.o
RuleTest.o: RuleTest.cpp RuleTest.h Rules.o
ControllerTest.o: ControllerTest.cpp ControllerTest.h Controller.o
StepTest.o: StepTest.cpp StepTest.h Steps.o

main.o: main.cpp

check: $(TESTAPP)
	@./$(TESTAPP)

clean:
	rm -f *.o $(TESTAPP) $(APP)
