```
create table client (
	CLIENTID char(3) CONSTRAINT PK_CLIENTID PRIMARY KEY CONSTRAINT STRTSWITH_C CHECK (CLIENTID LIKE 'C%'),
	NAME varchar(10),
	PHONE char(14) CONSTRAINT PHONE_FORMAT CHECK (PHONE like '+91-%' or PHONE like '+81-%' or PHONE like '+31-%' or PHONE like '+48-%' or PHONE like '+44-%'));

```
