<GameFile>
  <PropertyGroup Name="PlayerUpgradeScene" Type="Scene" ID="037393e8-19b9-4b7e-83a2-fbf8bda2343b" Version="2.3.3.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" Visible="False" Tag="237" ctype="GameNodeObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="Sprite_Background" ActionTag="-182277926" Tag="316" IconVisible="False" ctype="SpriteObjectData">
            <Size X="960.0000" Y="640.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Resource/background.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Text_Title" ActionTag="797562638" Tag="388" IconVisible="False" LeftMargin="214.0000" RightMargin="214.0000" BottomMargin="541.0000" FontSize="60" LabelText="Player Upgrade" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
            <Size X="442.0000" Y="83.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
            <Position X="480.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="1.0000" />
            <PreSize X="0.4823" Y="0.1484" />
            <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
            <OutlineColor A="255" R="30" G="144" B="255" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Sprite_GuideLine" ActionTag="-358182099" Tag="536" IconVisible="False" LeftMargin="1.0000" RightMargin="1.0000" TopMargin="689.0000" BottomMargin="-51.0000" ctype="SpriteObjectData">
            <Size X="958.0000" Y="2.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="-50.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="-0.0781" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Resource/guideLine.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Node_GoldNumber" ActionTag="-883127292" Tag="347" IconVisible="True" LeftMargin="480.0000" RightMargin="480.0000" TopMargin="140.0000" BottomMargin="500.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="Sprite_GoldCoin" ActionTag="-732922275" Tag="348" IconVisible="False" HorizontalEdge="LeftEdge" VerticalEdge="TopEdge" LeftMargin="-87.0000" RightMargin="35.0000" TopMargin="-26.0000" BottomMargin="-26.0000" ctype="SpriteObjectData">
                <Size X="52.0000" Y="52.0000" />
                <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                <Position X="-35.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0542" Y="0.0812" />
                <FileData Type="Normal" Path="Resource/goldCoin.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_GoldNumber" ActionTag="1727732741" Tag="349" IconVisible="False" HorizontalEdge="LeftEdge" VerticalEdge="TopEdge" LeftMargin="-30.0000" RightMargin="-82.0000" TopMargin="-32.5000" BottomMargin="-32.5000" FontSize="48" LabelText="9999" HorizontalAlignmentType="HT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="112.0000" Y="65.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="-30.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <OutlineColor A="255" R="0" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="480.0000" Y="500.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.7813" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="Button_MainMenu" ActionTag="1802285559" Tag="62" IconVisible="False" LeftMargin="20.0000" RightMargin="790.0000" TopMargin="20.0000" BottomMargin="570.0000" TouchEnable="True" FontSize="24" ButtonText="Main Menu" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="150.0000" Y="50.0000" />
            <AnchorPoint ScaleY="1.0000" />
            <Position X="20.0000" Y="620.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="173" G="216" B="230" />
            <PrePosition X="0.0208" Y="0.9688" />
            <PreSize X="0.1563" Y="0.0781" />
            <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
            <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="ScrollView_UpgradeItems" ActionTag="-845245168" Tag="420" IconVisible="False" HorizontalEdge="RightEdge" LeftMargin="300.0000" RightMargin="50.0000" TopMargin="190.0000" BottomMargin="50.0000" TouchEnable="True" ClipAble="True" BackColorAlpha="102" ComboBoxIndex="1" ColorAngle="90.0000" IsBounceEnabled="True" ScrollDirectionType="Vertical" ctype="ScrollViewObjectData">
            <Size X="610.0000" Y="400.0000" />
            <Children>
              <AbstractNodeData Name="Node_JumpType" ActionTag="1639665776" Tag="90" IconVisible="True" RightMargin="610.0000" TopMargin="30.0000" BottomMargin="420.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="Text_Item" ActionTag="-1571609055" Tag="91" IconVisible="False" LeftMargin="10.0000" RightMargin="-359.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="22" LabelText="Jump Type:" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="120.0000" Y="29.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="10.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="0" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="26" G="26" B="26" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_Desc" ActionTag="83341432" Tag="488" IconVisible="False" LeftMargin="158.0000" RightMargin="-380.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="22" LabelText="Focus on the ground" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="222.0000" Y="29.0000" />
                    <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                    <Position X="380.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Button_Item" ActionTag="-1997573725" Tag="92" IconVisible="False" LeftMargin="400.0000" RightMargin="-520.0000" TopMargin="-22.5000" BottomMargin="-22.5000" TouchEnable="True" FontSize="20" ButtonText="Upgrade" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="120.0000" Y="45.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="400.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="173" G="216" B="230" />
                    <PrePosition />
                    <PreSize X="0.6000" Y="0.9000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                    <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
                    <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Image_GoldCoin" ActionTag="-1611072317" Tag="95" IconVisible="False" LeftMargin="525.0000" RightMargin="-577.0000" TopMargin="-26.0000" BottomMargin="-26.0000" Scale9Width="52" Scale9Height="52" ctype="ImageViewObjectData">
                    <Size X="52.0000" Y="52.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="525.0000" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="Resource/goldCoin.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_GoldNumber" ActionTag="89586527" Tag="94" IconVisible="False" LeftMargin="555.0000" RightMargin="-597.0000" TopMargin="-17.0000" BottomMargin="-17.0000" FontSize="20" LabelText="999" HorizontalAlignmentType="HT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="36.0000" Y="28.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="555.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_Max" ActionTag="-1880866099" Tag="109" IconVisible="False" LeftMargin="430.0000" RightMargin="-481.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="22" LabelText="MAX" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="51.0000" Y="29.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="430.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="0" B="0" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position Y="420.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition Y="0.9333" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="Node_MaxHeartNum" ActionTag="-2001451665" Tag="99" IconVisible="True" RightMargin="610.0000" TopMargin="80.0000" BottomMargin="370.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="Text_Item" ActionTag="1055129963" Tag="100" IconVisible="False" LeftMargin="10.0000" RightMargin="-220.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="22" LabelText="Max Heart Number:" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="210.0000" Y="29.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="10.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="0" B="255" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="26" G="26" B="26" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_Number" ActionTag="1815231597" Tag="483" IconVisible="False" LeftMargin="269.0000" RightMargin="-371.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="22" LabelText="9.9 -&gt; 9.9" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="102.0000" Y="29.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="320.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Button_Item" ActionTag="1191583613" Tag="101" IconVisible="False" LeftMargin="400.0000" RightMargin="-520.0000" TopMargin="-22.5000" BottomMargin="-22.5000" TouchEnable="True" FontSize="20" ButtonText="Upgrade" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="120.0000" Y="45.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="400.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="173" G="216" B="230" />
                    <PrePosition />
                    <PreSize X="0.6000" Y="0.9000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                    <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
                    <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Image_GoldCoin" ActionTag="-450353512" Tag="102" IconVisible="False" LeftMargin="525.0000" RightMargin="-577.0000" TopMargin="-26.0000" BottomMargin="-26.0000" Scale9Width="52" Scale9Height="52" ctype="ImageViewObjectData">
                    <Size X="52.0000" Y="52.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="525.0000" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="Resource/goldCoin.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_GoldNumber" ActionTag="2110862136" Tag="103" IconVisible="False" LeftMargin="555.0000" RightMargin="-597.0000" TopMargin="-17.0000" BottomMargin="-17.0000" FontSize="20" LabelText="999" HorizontalAlignmentType="HT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="36.0000" Y="28.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="555.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_Max" ActionTag="-365168145" Tag="110" IconVisible="False" LeftMargin="430.0000" RightMargin="-481.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="22" LabelText="MAX" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="51.0000" Y="29.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="430.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="0" B="0" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position Y="370.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition Y="0.8222" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="Node_Strength" ActionTag="2000846781" Tag="465" IconVisible="True" RightMargin="610.0000" TopMargin="130.0000" BottomMargin="320.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="Text_Item" ActionTag="-891500697" Tag="466" IconVisible="False" LeftMargin="10.0000" RightMargin="-170.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="22" LabelText="Jump Strength:" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="160.0000" Y="29.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="10.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="0" B="255" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="26" G="26" B="26" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_Number" ActionTag="549613037" Tag="484" IconVisible="False" LeftMargin="269.0000" RightMargin="-371.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="22" LabelText="999 -&gt; 999" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="118.0000" Y="29.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="320.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Button_Item" ActionTag="302332534" Tag="467" IconVisible="False" LeftMargin="400.0000" RightMargin="-520.0000" TopMargin="-22.5000" BottomMargin="-22.5000" TouchEnable="True" FontSize="20" ButtonText="Upgrade" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="120.0000" Y="45.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="400.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="173" G="216" B="230" />
                    <PrePosition />
                    <PreSize X="0.6000" Y="0.9000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                    <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
                    <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Image_GoldCoin" ActionTag="-409619955" Tag="468" IconVisible="False" LeftMargin="525.0000" RightMargin="-577.0000" TopMargin="-26.0000" BottomMargin="-26.0000" Scale9Width="52" Scale9Height="52" ctype="ImageViewObjectData">
                    <Size X="52.0000" Y="52.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="525.0000" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="Resource/goldCoin.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_GoldNumber" ActionTag="-1557470118" Tag="469" IconVisible="False" LeftMargin="555.0000" RightMargin="-597.0000" TopMargin="-17.0000" BottomMargin="-17.0000" FontSize="20" LabelText="999" HorizontalAlignmentType="HT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="36.0000" Y="28.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="555.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_Max" ActionTag="-973920525" Tag="470" IconVisible="False" LeftMargin="430.0000" RightMargin="-481.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="22" LabelText="MAX" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="51.0000" Y="29.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="430.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="0" B="0" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position Y="320.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition Y="0.7111" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="Node_PowerTime" ActionTag="-1814495845" Tag="104" IconVisible="True" RightMargin="610.0000" TopMargin="180.0000" BottomMargin="270.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="Text_Item" ActionTag="-37496380" Tag="105" IconVisible="False" LeftMargin="10.0000" RightMargin="-176.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="22" LabelText="Focus Duration:" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="166.0000" Y="29.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="10.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="0" G="193" B="255" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="26" G="26" B="26" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_Number" ActionTag="1500221645" Tag="485" IconVisible="False" LeftMargin="274.0000" RightMargin="-366.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="20" LabelText="9.99s -&gt; 9.99s" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="136.0000" Y="26.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="320.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Button_Item" ActionTag="-1694676229" Tag="106" IconVisible="False" LeftMargin="400.0000" RightMargin="-520.0000" TopMargin="-22.5000" BottomMargin="-22.5000" TouchEnable="True" FontSize="20" ButtonText="Upgrade" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="120.0000" Y="45.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="400.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="173" G="216" B="230" />
                    <PrePosition />
                    <PreSize X="0.6000" Y="0.9000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                    <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
                    <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Image_GoldCoin" ActionTag="190371965" Tag="107" IconVisible="False" LeftMargin="525.0000" RightMargin="-577.0000" TopMargin="-26.0000" BottomMargin="-26.0000" Scale9Width="52" Scale9Height="52" ctype="ImageViewObjectData">
                    <Size X="52.0000" Y="52.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="525.0000" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="Resource/goldCoin.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_GoldNumber" ActionTag="638109530" Tag="108" IconVisible="False" LeftMargin="555.0000" RightMargin="-597.0000" TopMargin="-17.0000" BottomMargin="-17.0000" FontSize="20" LabelText="999" HorizontalAlignmentType="HT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="36.0000" Y="28.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="555.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_Max" ActionTag="981130007" Tag="111" IconVisible="False" LeftMargin="430.0000" RightMargin="-481.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="22" LabelText="MAX" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="51.0000" Y="29.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="430.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="0" B="0" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position Y="270.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition Y="0.6000" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="Node_GuidelineTime" ActionTag="-2006979114" Tag="471" IconVisible="True" RightMargin="610.0000" TopMargin="230.0000" BottomMargin="220.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="Text_Item" ActionTag="-1118763688" Tag="472" IconVisible="False" LeftMargin="10.0000" RightMargin="-215.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="18" LabelText="Item Duration (Guideline):" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="223.0000" Y="24.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="10.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="0" G="193" B="255" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="26" G="26" B="26" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_Number" ActionTag="2059330000" Tag="486" IconVisible="False" LeftMargin="248.0000" RightMargin="-392.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="20" LabelText="99.9s -&gt; 99.9s" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="136.0000" Y="26.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="320.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Button_Item" ActionTag="-804300560" Tag="473" IconVisible="False" LeftMargin="400.0000" RightMargin="-520.0000" TopMargin="-22.5000" BottomMargin="-22.5000" TouchEnable="True" FontSize="20" ButtonText="Upgrade" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="120.0000" Y="45.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="400.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="173" G="216" B="230" />
                    <PrePosition />
                    <PreSize X="0.6000" Y="0.9000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                    <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
                    <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Image_GoldCoin" ActionTag="-1504165673" Tag="474" IconVisible="False" LeftMargin="525.0000" RightMargin="-577.0000" TopMargin="-26.0000" BottomMargin="-26.0000" Scale9Width="52" Scale9Height="52" ctype="ImageViewObjectData">
                    <Size X="52.0000" Y="52.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="525.0000" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="Resource/goldCoin.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_GoldNumber" ActionTag="-192520752" Tag="475" IconVisible="False" LeftMargin="555.0000" RightMargin="-597.0000" TopMargin="-17.0000" BottomMargin="-17.0000" FontSize="20" LabelText="999" HorizontalAlignmentType="HT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="36.0000" Y="28.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="555.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_Max" ActionTag="1659327827" Tag="476" IconVisible="False" LeftMargin="430.0000" RightMargin="-481.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="22" LabelText="MAX" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="51.0000" Y="29.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="430.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="0" B="0" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position Y="220.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition Y="0.4889" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="Node_EnlargeTime" ActionTag="1112329976" Tag="477" IconVisible="True" RightMargin="610.0000" TopMargin="280.0000" BottomMargin="170.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="Text_Item" ActionTag="961920425" Tag="478" IconVisible="False" LeftMargin="10.0000" RightMargin="-193.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="18" LabelText="Item Duration (Enlarge):" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="206.0000" Y="24.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="10.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="0" G="193" B="255" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="26" G="26" B="26" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_Number" ActionTag="2116684636" Tag="487" IconVisible="False" LeftMargin="248.0000" RightMargin="-392.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="20" LabelText="99.9s -&gt; 99.9s" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="136.0000" Y="26.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="320.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Button_Item" ActionTag="-1646659312" Tag="479" IconVisible="False" LeftMargin="400.0000" RightMargin="-520.0000" TopMargin="-22.5000" BottomMargin="-22.5000" TouchEnable="True" FontSize="20" ButtonText="Upgrade" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="120.0000" Y="45.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="400.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="173" G="216" B="230" />
                    <PrePosition />
                    <PreSize X="0.6000" Y="0.9000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                    <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
                    <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Image_GoldCoin" ActionTag="-1957470504" Tag="480" IconVisible="False" LeftMargin="525.0000" RightMargin="-577.0000" TopMargin="-26.0000" BottomMargin="-26.0000" Scale9Width="52" Scale9Height="52" ctype="ImageViewObjectData">
                    <Size X="52.0000" Y="52.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="525.0000" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="Resource/goldCoin.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_GoldNumber" ActionTag="-1748481644" Tag="481" IconVisible="False" LeftMargin="555.0000" RightMargin="-597.0000" TopMargin="-17.0000" BottomMargin="-17.0000" FontSize="20" LabelText="999" HorizontalAlignmentType="HT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="36.0000" Y="28.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="555.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_Max" ActionTag="-384211253" Tag="482" IconVisible="False" LeftMargin="430.0000" RightMargin="-481.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="22" LabelText="MAX" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="51.0000" Y="29.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="430.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="0" B="0" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position Y="170.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition Y="0.3778" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="Node_ShrinkTime" ActionTag="659385309" Tag="489" IconVisible="True" RightMargin="610.0000" TopMargin="330.0000" BottomMargin="120.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="Text_Item" ActionTag="-1792585570" Tag="490" IconVisible="False" LeftMargin="10.0000" RightMargin="-193.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="18" LabelText="Item Duration (Shrink):" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="195.0000" Y="24.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="10.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="0" G="193" B="255" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="26" G="26" B="26" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_Number" ActionTag="1644332524" Tag="491" IconVisible="False" LeftMargin="248.0000" RightMargin="-392.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="20" LabelText="99.9s -&gt; 99.9s" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="136.0000" Y="26.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="320.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Button_Item" ActionTag="588982347" Tag="492" IconVisible="False" LeftMargin="400.0000" RightMargin="-520.0000" TopMargin="-22.5000" BottomMargin="-22.5000" TouchEnable="True" FontSize="20" ButtonText="Upgrade" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="120.0000" Y="45.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="400.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="173" G="216" B="230" />
                    <PrePosition />
                    <PreSize X="0.6000" Y="0.9000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                    <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
                    <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Image_GoldCoin" ActionTag="-1140126296" Tag="493" IconVisible="False" LeftMargin="525.0000" RightMargin="-577.0000" TopMargin="-26.0000" BottomMargin="-26.0000" Scale9Width="52" Scale9Height="52" ctype="ImageViewObjectData">
                    <Size X="52.0000" Y="52.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="525.0000" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="Resource/goldCoin.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_GoldNumber" ActionTag="-1864723844" Tag="494" IconVisible="False" LeftMargin="555.0000" RightMargin="-597.0000" TopMargin="-17.0000" BottomMargin="-17.0000" FontSize="20" LabelText="999" HorizontalAlignmentType="HT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="36.0000" Y="28.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="555.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_Max" ActionTag="358007226" Tag="495" IconVisible="False" LeftMargin="430.0000" RightMargin="-481.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="22" LabelText="MAX" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="51.0000" Y="29.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="430.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="0" B="0" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position Y="120.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition Y="0.2667" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="Node_ShieldTime" ActionTag="-1551931007" Tag="496" IconVisible="True" RightMargin="610.0000" TopMargin="380.0000" BottomMargin="70.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="Text_Item" ActionTag="1690713684" Tag="497" IconVisible="False" LeftMargin="10.0000" RightMargin="-193.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="18" LabelText="Item Duration (Shield):" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="194.0000" Y="24.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="10.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="0" G="193" B="255" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="26" G="26" B="26" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_Number" ActionTag="-700567090" Tag="498" IconVisible="False" LeftMargin="248.0000" RightMargin="-392.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="20" LabelText="99.9s -&gt; 99.9s" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="136.0000" Y="26.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="320.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Button_Item" ActionTag="1816863886" Tag="499" IconVisible="False" LeftMargin="400.0000" RightMargin="-520.0000" TopMargin="-22.5000" BottomMargin="-22.5000" TouchEnable="True" FontSize="20" ButtonText="Upgrade" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="120.0000" Y="45.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="400.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="173" G="216" B="230" />
                    <PrePosition />
                    <PreSize X="0.6000" Y="0.9000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                    <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
                    <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Image_GoldCoin" ActionTag="-789012195" Tag="500" IconVisible="False" LeftMargin="525.0000" RightMargin="-577.0000" TopMargin="-26.0000" BottomMargin="-26.0000" Scale9Width="52" Scale9Height="52" ctype="ImageViewObjectData">
                    <Size X="52.0000" Y="52.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="525.0000" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="Resource/goldCoin.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_GoldNumber" ActionTag="-1429331347" Tag="501" IconVisible="False" LeftMargin="555.0000" RightMargin="-597.0000" TopMargin="-17.0000" BottomMargin="-17.0000" FontSize="20" LabelText="999" HorizontalAlignmentType="HT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="36.0000" Y="28.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="555.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_Max" ActionTag="-250245763" Tag="502" IconVisible="False" LeftMargin="430.0000" RightMargin="-481.0000" TopMargin="-14.5000" BottomMargin="-14.5000" FontSize="22" LabelText="MAX" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="51.0000" Y="29.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="430.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="0" B="0" />
                    <PrePosition />
                    <PreSize X="1.4000" Y="1.8000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position Y="70.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition Y="0.1556" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="1.0000" />
            <Position X="910.0000" Y="50.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.9479" Y="0.0781" />
            <PreSize X="0.6354" Y="0.6250" />
            <SingleColor A="255" R="0" G="0" B="0" />
            <FirstColor A="255" R="255" G="150" B="100" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
            <InnerNodeSize Width="610" Height="450" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>