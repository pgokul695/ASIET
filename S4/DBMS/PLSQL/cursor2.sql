DECLARE 
	CURSOR c IS SELECT * FROM studres;
	v_avg int;
	v_tot int;
	v_grade varchar(3);
BEGIN
	FOR i IN c LOOP
		v_tot := i.paper1 + i.paper2 + i.paper3 +i.paper4;
		v_avg := v_tot/4;
		
		IF v_avg >=85 THEN
			v_grade := 'A';
		ELSIF v_avg >=65 THEN
			v_grade := 'B';
		ELSIF v_avg >=40 THEN
			v_grade := 'C';
		ELSIF v_avg >=25 THEN
			v_grade := 'D';
		ELSE
			v_grade := 'E';
		END IF;
		
		UPDATE studres
		SET averg = v_avg, grade= v_grade
		WHERE regno = i.regno;
	END LOOP;
END;
/
