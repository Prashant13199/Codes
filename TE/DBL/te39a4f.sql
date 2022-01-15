declare
radius number(5);
area number(5,2);
pi constant number(4,2):=3.14;
begin
radius:=&radius;
area:=pi*power(radius,2);
insert into circle_area values(radius,area);
end;
/
