declare
empno number(4);
hiredate date;
sal number(5,2);
uempno number(4);
ht number(5);
begin
	uempno:=&uempno;
	select SYSDATE-hiredate into ht from emp where empno=uempno;
	if ht>365 then
		update emp set sal=sal+1000 where empno=uempno;
	end if;
end;
/
