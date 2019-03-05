/*
    scoreboard.ino

    This program takes a digital signal from a pushbutton and based on how many
    times the button is pushed, the program imcrements through a set of states.
    Each state takes a set of digital lines which control lights and maps them
    to a number. 

    The program has two broad sections. The first manages the state of the
    scoreboard, while the second lights up LED sections based on that state. The
    LED control section assumes the following positions for the LEDs. 

          1
        _____
     2 |     | 3
       |_____|
     5 |  4  | 6
       |_____|
          7

*/

/**********************
** Program Variables **
**********************/
int score = 0;
int button = 8;
int lastButtonState = 0;

void setup()
{
    /*****************************
    ** Setup Input/Output Lines ** 
    *****************************/

    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);

    pinMode(button, INPUT);
    Serial.begin(9600);
}

void loop()
{
    /*********************
    ** Scoreboard State **
    *********************/

    // Serial monitor for debugging.
    // Serial.println(score);
    // delay(50);

    // Digital read from whatever line the button is on.
    int buttonState = digitalRead(button);

    // Only try to update if button state has changed.
    if (buttonState != lastButtonState)
    {
        // If button was previously LOW, and is now HIGH, increment score.
        if (buttonState == HIGH)
        {
            score++;
        }

        // Update last state to avoid multiple clicks on single push.
        lastButtonState = buttonState;
    }

    // If the score goes above 9, we should reset to 0.
    if (score < 9)
    {
        score = 0;
    }

    /****************
    ** LED Control **
    ****************/

    if (score == 0)
    {
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
    }

    if (score == 1)
    {
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
    }

    if (score == 2)
    {
        digitalWrite(1, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
    }

    if (score == 3)
    {
        digitalWrite(1, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
    }

    if (score == 4)
    {
        digitalWrite(1, LOW);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
    }

    if (score == 5)
    {
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
    }

    if (score == 6)
    {
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
    }

    if (score == 7)
    {
        digitalWrite(1, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
    }

    if (score == 8)
    {
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
    }

    if (score == 9)
    {
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
    }
}