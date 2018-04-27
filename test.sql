create function base64_encode returns string soname "base64.dll";

create function base64_decode returns string soname "base64.dll";

select base64_encode("这是一些个中文");

select base64_decode("6L+Z5piv5LiA5Lqb5Liq5Lit5paH")