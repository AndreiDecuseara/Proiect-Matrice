# Proiect-Matrice
Componente utilizate:

1.Matrice 8 * 8 pe care se va juca 
2.Ultrasonic utilizat la masurarea distantei si miscarea celor 2 puncte pe matrice
3.Display (afisare scor, high score, mesaje, instructiuni, vieti si altele) pentru interactiunea cu jucatorul
4.breadboard - conectare fire si alte componenete
5. potentiometru- setare nivelul jocului cu procente
6. buzzer pentru emitere sunete la deschiderea jocului, pentru greseli si finalizare
7.buton pentru restart joc, intrare in joc si altele
8. o baterie


Descriere joc:

Jocul se bazeaza pe miscarea jucatorului, astfel incat senzorul de miscare citeste distanta fata de obiectul cu care s-a calibrat. Odata cu aceasta miscare, se vor muta pe matrice 2 puncte centrale care se vor misca pe axa y pe centrul matricei. Scopul jocului este acela de a te feri de 2 puncte random care se misca pe axa x din 2 parti diferite. Jucatorul are 3 vieti si un scor care este proportional cu viteza jocului . 


Descriere cod:

 Vedeta jocului pot sa zic ca este senzorul de miscare, care masoara distanta initiala apoi in functie de aceasta misca punctele. Creez o functie de miscare pentru aceasta care analizeaza la anumiti pasi stadiul ultrasonicului si daca este + sau - un anumit numar de cm, se vor muta punctele luminoase pe matrice.
  Pentru generarea inamicilor, folosesc functia random, si apoi intr-un singur for, vin din parti diferite cu ambele puncte pe linia respactiva.
   Variabila " viata " se decrementeaza in momentul in care punctele centrale controlate de ultrasonic, se ating cu inamicii. Buzzer-ul scoate si el un sunete in momentul in care se pierde o viata.
   Jocul se termina in momentul in care se ramane fara vieti.

Videoclip matrice:
https://www.youtube.com/watch?v=7nWSSowJuI4&feature=share&fbclid=IwAR2Ro2QKOH2Zw_HzprlV9xk2rwDCqzSehXK0m9okCrwq1O1RKq1QkykIU8M

