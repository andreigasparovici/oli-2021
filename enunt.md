# zid

Limita de timp: 0.1 secunde

Limita de memorie: 1000 kilobytes

Gigel doreşte să construiască un zid de înălţime N din piese lego. El are la dispoziţie piese de 2 feluri: verzi (de înălţime 1) şi roşii (de orice înălţime >= 3). De asemenea, el decide ca între oricare două piese roşii să pună cel puţin o piesă verde, astfel încât zidul să nu conţină două piese roşii vecine. Fiind că nu se pricepe la numărat, Gigel vă întreabă în câte moduri poate construi zidul.

## Date de intrare

Pe prima linia a fişierului zid.in se află numărul N.

## Date de ieşire

Pe prima linie a fişierului zid.out se va afişa un număr R, reprezentând numărul de moduri în care Gigel poate construi zidul __modulo 666013__.

## Restricţii şi precizări

* Pentru teste în valoare de 30p, 5 <= N <= 30
* Pentru teste în valoare de 70p, 30 <= N <= 7000
* Gigel dispune de un număr nelimitat de piese.

## Exemplu

<table>
  
  <tr>
    <th>zid.in</th>
    <th>zid.out</th>
    <th>Explicaţie</th>
  </tr>
  <tr>
    <td>4</td>
    <td>4</td>
    <td>
       Notând cu V piesele verzi şi cu R piesele roşii, pentru N = 4 se pot construi următoarele ziduri (privite orizontal):
       <pre>
[V] [V] [V] [V] 
[V] [    R    ]
[    R    ] [V]
[      R      ]
      </pre>
    </td>
  </tr>
</table>
