declare
ename varchar2(10);
eroll number(5);
id number(5);
eamt number(7,2);
begin
ename:=&ename;
eroll:=&eroll;
select SYSDATE - dateofisuue into id from borrower where rollin=eroll;
if id between 15 and 30 then
eamt:=(id-15)*5;
insert into fine values(eroll,sysdate,eamt);
end if;
if id>30 then
eamt:=(id-30)*50;
insert into fine values(eroll,sysdate,eamt);
end if;
update borrower set status='R' where rollin=eroll;
end;
/



