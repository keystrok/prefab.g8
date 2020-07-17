open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
      //TIP: useful for debugging
      //      "scrollView":
      //        style(
      //          ~backgroundColor="lightblue",
      //          (),
      //        ),

      //      "scrollView": style(),
      "engine": style(~position=`absolute, ~right=0.->dp, ()),
      ////      "sectionContainer":
      ////        style(
      ////          ~marginTop=32.->dp,
      ////          ~marginBottom=32.->dp,
      ////          ~paddingHorizontal=24.->dp,
      ////          ~flexDirection=`row,
      ////          ~justifyContent=`flexStart,
      ////          ~alignItems=`stretch,
      ////          //          ~backgroundColor="black", //TIP: useful for debugging
      ////          (),
      ////        ),
      //      "sectionTitle":
      //        style(
      //          //          ~flex=1.,
      //          ~fontSize=36.,
      //          ~fontWeight=`_700,
      //          ~color=Colours.kiwiGreen,
      //          //          ~backgroundColor="grey",
      //          (),
      //        ),
      //      "sectionDescription":
      //        style(
      //          ~paddingVertical=20.->dp,
      //          ~fontSize=18.,
      //          ~fontWeight=`_400,
      //          ~color=Colours.kiwiGrey,
      //          (),
      //        ),
            "footer":
              style(
                ~fontSize=12.,
                ~fontWeight=`_600,
                ~padding=4.->dp,
                ~paddingRight=12.->dp,
                ~textAlign=`right,
                (),
              ),
      //      "paginator":
      //        viewStyle(
      //          ~bottom=50.->dp,
      //          ~height=30.->dp,
      //          ~flex=1.,
      //          ~flexDirection=`row,
      //          ~justifyContent=`center,
      //          (),
      //        ),
      //      "paginatorDots":
      //        viewStyle(~flex=2., ~flexDirection=`row, ~justifyContent=`center, ()),
      //      "paginatorDot":
      //        viewStyle(
      //          ~width=7.->dp,
      //          ~height=7.->dp,
      //          ~borderRadius=7.,
      //          ~marginHorizontal=3.->dp,
      //          ~backgroundColor=Colours.kiwiGreen,
      //          ~opacity=0.25,
      //          (),
      //        ),
      //      "paginatorDotActive": viewStyle(~opacity=1., ()),
      //      "walkthroughPageStyle":
      //        style(
      //          ~flexDirection=`column,
      //          ~justifyContent=`center,
      //          ~alignItems=`center,
      //          ~height=100.->pct,
      //          (),
      //        ),
      //      "skip":
      //        style(
      //          ~flex=1.,
      //          ~flexDirection=`row,
      //          ~justifyContent=`center,
      //          ~color="#337BF6",
      //          ~bottom=12.->dp,
      //          (),
      //        ),
    })
  );