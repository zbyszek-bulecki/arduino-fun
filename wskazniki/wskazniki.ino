void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  int8_t india = 1;
  Serial.print("Moja liczba to: ");
  Serial.println((int)&india, HEX);
  int8_t jouliet = 1;
  Serial.println((int)&jouliet, HEX);
  Serial.println(sizeof(jouliet));
  int8_t *k = 0x8FA; //biorę komórkę pamięci pod adresem 8FA i mówię procesorowi, ze tam się znajduje 1B danych, które naley potraktować jako liczbę ze znakiem
  Serial.println(*k);
  int16_t *lima = 0x8FA;
  Serial.println(*lima);
  Serial.println("====== ====  ======");

  Serial.println(india);
  Serial.println(jouliet);

  *lima = 32637;
  Serial.println(india);
  Serial.println(jouliet);
  Serial.println("====== ====  ======");


}

void loop() {
  // put your main code here, to run repeatedly:

  // w jednej linijce uzywamy gwiazdki (uzyc zmiennej pod wskaznikiem - masz wskaznik a chcesz uzyc zmiennej) i ampersanda (dostac adres do komorki - wskaznik na zmienna)

}
