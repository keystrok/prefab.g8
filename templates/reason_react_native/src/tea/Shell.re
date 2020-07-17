open ReactNative;
open Styles;

module Shell = {
  [@react.component]
  let make = (~children) =>
    <>
      <StatusBar barStyle=`darkContent />
      <SafeAreaView>
        <View style=Style.(style(~backgroundColor=Flex.white, ()))>
          {Global.hermesInternal->Belt.Option.isNone
             ? React.null
             : <View style=styles##engine>
                 <Text style=styles##footer>
                   "Engine: Hermes"->React.string
                 </Text>
               </View>}
          children
        </View>
      </SafeAreaView>
    </>;
};