#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

int prior;

TaskHandle_t task1Handle;
TaskHandle_t task2Handle;

void task1(void *pvParameters) {
  while (true) {
    Serial.print("Task 1 is running \t");
    vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
  }
}

void task2(void *pvParameters) {
  while (true) {
    Serial.print("Task 2 is running \t");
    if (prior == 1)
    {
      vTaskDelay(pdMS_TO_TICKS(500)); // Delay for 500 milliseconds  
    }
    else
    {
      vTaskDelay(pdMS_TO_TICKS(2000)); // Delay for 500 milliseconds
    }
  }
}

void setup() {
  Serial.begin(9600);
  xTaskCreate(task1, "Task 1", 10000, NULL, 1, &task1Handle);
  xTaskCreate(task2, "Task 2", 10000, NULL, 2, &task2Handle);
}

void loop() {
  Serial.println("Loop is running \t");
  delay(1000); // Delay for 1 second
  prior = 0;
}
