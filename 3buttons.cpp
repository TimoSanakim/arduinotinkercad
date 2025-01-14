const int buttonPin = 3; // Button connected to digital pin 3
int x = 0; // Initialize x to 0
int lastButtonState = LOW; // Previous state of the button
int currentButtonState; // Current state of the button

void setup() {
  // Initialize the serial communication:
  Serial.begin(9600);

  // Initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Read the state of the pushbutton:
  currentButtonState = digitalRead(buttonPin);

  // Check if the button is pressed (HIGH) and was not pressed before:
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    x++; // Increment x
    printMessage(x); // Call the function to print the message
  }

  // Save the current state as the last state for the next loop iteration:
  lastButtonState = currentButtonState;

  // Small delay to avoid bouncing issues:
  delay(50);
}

// Function to print specific messages based on the value of x
void printMessage(int x) {
  if (x == 2) {
    Serial.println("This is an apple");
  } else if (x == 3) {
    Serial.println("This is a banana");
  } else if (x == 4) {
    Serial.println("This is a pear");
  } else {
    Serial.print("message ");
    Serial.println(x);
  }
}
