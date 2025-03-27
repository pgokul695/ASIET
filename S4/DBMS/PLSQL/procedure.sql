DECLARE
	a number;
	b number;
	c number;
PROCEDURE findmin(x in number, y in number, z out number) IS
BEGIN
	if x<y Then
		z:=x;
	ELSE
		z:=y;
	End if;
END;

BEGIN
	a:=25;
	b:=35;
	findmin(a,b,c);
	dbms_output.put_line('The minimum of(25,35)is:'||c);

END;
/	


