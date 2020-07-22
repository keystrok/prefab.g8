open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
      "engine": style(~position=`absolute, ~right=0.->dp, ()),

      "content":
        style(
          ~display=`flex,
          ~flexDirection=`column,
          ~justifyContent=`center,
          ~alignItems=`center,
          ~height=100.->pct,
          (),
        ),

      "footer":
        style(
          ~fontSize=12.,
          ~fontWeight=`_600,
          ~padding=4.->dp,
          ~paddingRight=12.->dp,
          ~textAlign=`right,
          (),
        ),
    })
  );