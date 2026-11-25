const int DAT = 11, CLK = 13, N = 8;   // N = LED 개수

void sendByte(uint8_t b) {
  for (int i = 7; i >= 0; i--) {
    digitalWrite(DAT, (b >> i) & 1);
    digitalWrite(CLK, HIGH);
    digitalWrite(CLK, LOW);
  }
}

void setup() {
  pinMode(DAT, OUTPUT);
  pinMode(CLK, OUTPUT);
}

void loop() {
  for (int i = 0; i < 4; i++) sendByte(0x00);   // 시작 프레임
  for (int i = 0; i < N; i++) {
    sendByte(0xE0 | 8);   // 밝기 (0~31)
    sendByte(0);          // Blue
    sendByte(0);          // Green
    sendByte(255);        // Red
  }
  for (int i = 0; i < 4; i++) sendByte(0xFF);   // 종료 프레임
  delay(500);
}