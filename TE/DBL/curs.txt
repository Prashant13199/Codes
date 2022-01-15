
DECLARE

   i number(5);
   n varchar(10);
   a varchar(10);
   i1 number(5);
   n1 varchar(10);
   a1 varchar(10);
   NOT_DUP number:=0; 
	
    CURSOR scur IS
      SELECT id,name,age FROM student1;
    
    CURSOR tcur IS
      SELECT sid,sname,age FROM student2;
BEGIN      
OPEN scur; 
    LOOP
        FETCH scur INTO i,n,a;
        OPEN tcur;
        LOOP
         
         FETCH tcur INTO i1,n1,a1;
        
        IF i = i1 THEN
              NOT_DUP:= 1;
        END IF;
        
        Exit WHEN tcur%NOTFOUND;
        END LOOP;
        
         IF NOT_DUP = 1 THEN
            NOT_DUP:= 0;
       ELSE      
           
           INSERT INTO student2
                    (sid,sname,age)
                    VALUES (i,n,a);  
        END IF;
        
       
      
      CLOSE tcur;
     EXIT WHEN scur%NOTFOUND;
   
    END LOOP;
    CLOSE scur;
END; 
/
