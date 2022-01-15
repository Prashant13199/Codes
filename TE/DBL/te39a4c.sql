declare
a number(5);
b number(5);
c number(5);
d number(5);
e number(5);
f number(5);
g number(5);
begin
a:=&a;
b:=&b;
c:=&c;
d:=&d;
e:=&e;
f:=&f;
g:=(a+b+c+d+e+f)/6;
dbms_output.put_line('Avg marks is'||g);
if (g>=80) then
dbms_output.put_line('Grade A');
elsif (g>=60 and g<80) then
dbms_output.put_line('Grade B');
elsif (g>=50 and g<60) then
dbms_output.put_line('Grade c');
else 
dbms_output.put_line('Grade D');
end if;
end;
/



