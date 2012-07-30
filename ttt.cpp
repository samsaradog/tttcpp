// main user input routine for ttt program

#include <iostream>
#include "Controller.h"

int main()
{
  Controller the_controller;

  string display_message;

  bool keep_playing = true;

  char response_buffer[1024];

  char response = 'Y';

  the_controller.addResponse(response, display_message);

  cout << display_message;

  while( keep_playing )
  {
    cin >> response_buffer;

    response = *response_buffer;

    keep_playing = the_controller.addResponse(response, display_message);

    cout << display_message;
  }

  return(0);
}
