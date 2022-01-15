declare
n number(5);
r number(5);
q number(5);
begin
n:=1234;
q:=0;
WHILE n <> 0
loop  
r:= MOD(n,10);  
q:= q + r;  
n:=Trunc(n / 10);  
end loop;  
dbms_output.Put_line('sum of digits = '||q);
end;
/  
