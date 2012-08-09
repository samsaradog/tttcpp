// file View.cpp

#include <cctype>
#include <iostream>
//#include <cstdlib>

#include "Controller.h"
#include "StepFactory.h"

//---------------------------------------------------------------

Controller::Controller() : human_m(), computer_m(), 
                           game_m(&human_m, &computer_m),
                           view_m(), continue_game_m(true),
                           step_m_p(NULL)
{
  StepFactory the_factory;

  step_m_p = the_factory.getSteps();

  // seed the random number generators

  srand(time(0));
}

//---------------------------------------------------------------

Controller::
~Controller()
{
  if ( NULL != step_m_p )
  {
    delete step_m_p;
    step_m_p = NULL;
  }
}

//---------------------------------------------------------------

bool Controller::addResponse(char input, string& message)
{
  bool return_value = true;

  switch (toupper(input))
  {
    case 'Y':
    {
      game_m.reset(&human_m, &computer_m);

      bool computer_first = ( 1 == (rand() % 2) );

      if ( computer_first )
      {
        message += "Computer moves first.\n";
        game_m.addMove(8, &computer_m);
      }
      else
      {
        message += "Human moves first.\n";
      }

      message += view_m.show(&human_m, &computer_m, &game_m);
      message += CT_MOVE_MESSAGE;
    }
    break;

    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
       int move = input - '0';
       int translated_move = mapper_m.humanToComputer(move);

       message.clear();

       bool more_moves = step_m_p->makeMove(translated_move,
                                            message,
                                            &human_m,
                                            &computer_m,
                                            &game_m);

       message += view_m.show(&human_m, &computer_m, &game_m);

       if ( more_moves )
         message += CT_MOVE_MESSAGE;
       else
         message += "Play again? (Y/N)\n";
    }
    break;

    case 'Q':
    case 'N':
    {
      message = CT_BYE_MESSAGE;
      return_value = false;
    }
    break;

    default:
    {
      message = CT_BAD_ENTRY_MESSAGE;
      message += CT_MOVE_MESSAGE;
      return_value = true;
    }
    break;
  }

  return return_value;
}


//---------------------------------------------------------------
