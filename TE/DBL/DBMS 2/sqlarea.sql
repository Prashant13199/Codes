declare 
pi constant number(5,2):=3.14;
radius number(3);
area number(10,2);
begin
	radius:=3;
	while radius<=7 loop
		area:=pi*power(radius,2);
		insert into Area_circle values(radius,area);
		radius:=radius+1;
	end loop;
end;
/
