#### Создайте файл, содержащий только «42» и НИЧЕГО больше.
#### Его имя будет:
#### "\?$*'KwaMe'*$?\"
#### Пример:
```
$>ls -lRa *waM* | cat -e
-rw---xr-- 1 75355 32015 2 Oct 2 12:21 "\?$*'KwaMe'*$?\"$
$>
```
##### $ touch -t [[CC]YY]MMDDhhmm[.SS]
![This is an image](properties.gif)
#### HowTo:
```
echo -e "42" | tr -d "\n" > \"\\\?\$\*\'KwaMe\'\*\$\?\\\"
touch -t 10021221 \"\\\?\$\*\'KwaMe\'\*\$\?\\\"
chmod 614 \"\\\?\$\*\'KwaMe\'\*\$\?\\\"
```
#### Test:
```
ls -lRa *waM* | cat -e 
```
#### Output:
```
-rw---xr--  1 dmitry  staff  2  2 Oct  2021 "\?$*'KwaMe'*$?\"$
```