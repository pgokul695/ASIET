DECLARE
	v_total electricity.total%TYPE;
	CURSOR c IS SELECT * FROM electricity;
BEGIN
	FOR i IN c LOOP
		BEGIN
			IF i.unit <=40 THEN
				v_total := i.rent;
			ELSIF i.unit <=80 THEN
				v_total := i.rent+(i.unit-40)*0.40;
			ELSE
				v_total := i.rent+(40*0.40)+(i.unit-80)*1.40;
			END IF;
			UPDATE electricity SET TOTAL = v_total
			WHERE cons_id=i.cons_id;
		END;
	END LOOP;
	COMMIT;
END;
/
