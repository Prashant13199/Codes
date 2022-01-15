declare
roll number(5);
name varchar2(30);
dt number(5);
fine number(10):=0;


begin
	roll:=&roll;
	name:=&name;
	select sysdate-dateofisue into dt from borrower where rollin=roll;
	if dt between 15 and 30 then
		dt:=dt-15;
		fine:=dt*5;
		insert into fine values(roll,sysdate,fine);
		update borrower set status='r' where rollin=roll;
	end if;
	if dt>30 then
		dt:=dt-30;
		fine:=dt*50;
		dt:=dt-15;
		fine:=fine+(dt*5);
		insert into fine values(roll,sysdate,fine);
		update borrower set status='r' where rollin=roll;
	end if;
end;
/
