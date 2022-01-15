declare 
cursor scur is select * from stu1;
id1 stu1.id%type;
name1 stu1.name%type;
age1 stu1.age%type;

cursor tcur is select * from stu2;
id2 stu2.sid%type;
name2 stu2.sname%type;
age2 stu2.sage%type;

dup number(5):=0;

begin
open tcur;
loop
	fetch tcur into id2,name2,age2;
	open scur;
	loop
		fetch scur into id1,name1,age1;
		if(id1=id2) then
			dup:=1; 
		end if;
		exit when (scur%NOTFOUND);
	end loop;
	close scur;
	if(dup=1) then
		dup:=0;
	else
		insert into stu1 values(id2,name2,age2);
	end if;
	exit when (tcur%NOTFOUND);
end loop;
close tcur;
end;
/
