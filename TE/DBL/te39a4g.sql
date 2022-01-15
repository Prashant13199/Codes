declare
ht number(5);
sal number(6,2);
uempno number(5);

begin
uempno:=&uempno;
select SYSDATE - hiredate into ht from emp where empno=uempno;
if ht>365 then
update emp set sal=sal+1000 where empno=uempno;
end if;
end;
/
