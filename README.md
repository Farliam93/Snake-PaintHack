# PaintHack

Anleitung:
1. Paint öffnen (kein Bild öffnen)(Wir brauchen den Fenster Titel Unbenannt).
2. Die Größe des Zeichenbereiches auf 400x400 Pixel anpassen.
3. Programm starten
4. Das Programm wartet bis Paint das erste mal den Focus besitzt.

Wenn der Basepointer und die Offsets in Zukunft nicht stimmen sollten:
Über Cheatengine wie bei allen anderen Spielen die Adresse des ersten Pixel suchen.
Doch der erste Pixel ist nicht der oberste linke. 

Paint legt die Daten der Pixel (3 Bytes) wie folgt ab:
![Screenshot_3](https://github.com/Farliam93/Snake-PaintHack/assets/116157943/ada270c2-6295-43f5-92c0-96d97ed500d5)

Suchen wir uns die Adresse dieses Pixel, sparen wir uns viel Arbeit, 
weil wir den gesamten Speicher in einem Stück ablegen können.

<iframe width="560" height="315" src="https://www.youtube.com/embed/SLF0-G_G68k?si=bcKoHnymDgyVAWO7" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
