<GameFile>
  <PropertyGroup Name="PlayerUpgradeItemNode" Type="Node" ID="f938cd42-9cb1-4ae2-be8d-277f3ac1a3be" Version="2.3.3.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Node" Tag="82" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="Panel_UpgradeItem" ActionTag="1991882990" Tag="96" IconVisible="False" LeftMargin="-305.0000" RightMargin="-305.0000" TopMargin="-50.0000" BottomMargin="-50.0000" TouchEnable="True" ClipAble="True" BackColorAlpha="191" ComboBoxIndex="1" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
            <Size X="610.0000" Y="100.0000" />
            <Children>
              <AbstractNodeData Name="ScrollView_Desc" ActionTag="1579981314" Tag="44" IconVisible="False" LeftMargin="20.0000" RightMargin="140.0000" TopMargin="40.0000" BottomMargin="10.0000" TouchEnable="True" ClipAble="True" BackColorAlpha="102" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" IsBounceEnabled="True" ScrollDirectionType="Vertical" ctype="ScrollViewObjectData">
                <Size X="450.0000" Y="50.0000" />
                <Children>
                  <AbstractNodeData Name="Text_Desc" ActionTag="-1455824644" Tag="45" IconVisible="False" PositionPercentYEnabled="True" RightMargin="227.0000" BottomMargin="21.0000" FontSize="22" LabelText="Focus on the ground" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="223.0000" Y="29.0000" />
                    <AnchorPoint ScaleY="1.0000" />
                    <Position Y="50.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition Y="1.0000" />
                    <PreSize X="0.4956" Y="0.5800" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleY="1.0000" />
                <Position X="20.0000" Y="60.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.0328" Y="0.6000" />
                <PreSize X="0.7377" Y="0.5000" />
                <SingleColor A="255" R="255" G="150" B="100" />
                <FirstColor A="255" R="255" G="150" B="100" />
                <EndColor A="255" R="255" G="255" B="255" />
                <ColorVector ScaleY="1.0000" />
                <InnerNodeSize Width="450" Height="50" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_Name" ActionTag="-1012507381" Tag="90" IconVisible="False" LeftMargin="10.0000" RightMargin="478.0000" TopMargin="5.0000" BottomMargin="66.0000" FontSize="22" LabelText="Jump Type:" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                <Size X="122.0000" Y="29.0000" />
                <AnchorPoint ScaleY="1.0000" />
                <Position X="10.0000" Y="95.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="0" />
                <PrePosition X="0.0164" Y="0.9500" />
                <PreSize X="0.2000" Y="0.2900" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <OutlineColor A="255" R="0" G="0" B="0" />
                <ShadowColor A="255" R="26" G="26" B="26" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_Item" ActionTag="-826620794" Tag="92" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="500.0000" TopMargin="20.0000" BottomMargin="20.0000" TouchEnable="True" FontSize="20" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="130" Scale9Height="38" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="110.0000" Y="60.0000" />
                <Children>
                  <AbstractNodeData Name="Node_GoldNumber" ActionTag="-1993704588" Tag="345" IconVisible="True" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="55.0000" RightMargin="55.0000" TopMargin="30.0000" BottomMargin="30.0000" ctype="SingleNodeObjectData">
                    <Size X="0.0000" Y="0.0000" />
                    <Children>
                      <AbstractNodeData Name="Sprite_GoldCoin" ActionTag="-928431420" Tag="332" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="-30.0000" RightMargin="-22.0000" TopMargin="-26.0000" BottomMargin="-26.0000" ctype="SpriteObjectData">
                        <Size X="52.0000" Y="52.0000" />
                        <AnchorPoint ScaleY="0.5000" />
                        <Position X="-30.0000" />
                        <Scale ScaleX="0.5000" ScaleY="0.5000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition />
                        <PreSize X="0.0000" Y="0.0000" />
                        <FileData Type="Normal" Path="Resource/Item/goldCoin.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_GoldNumber" ActionTag="1527802867" Tag="333" IconVisible="False" PositionPercentYEnabled="True" HorizontalEdge="LeftEdge" RightMargin="-55.0000" TopMargin="-15.5000" BottomMargin="-15.5000" FontSize="22" LabelText="9999" HorizontalAlignmentType="HT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="55.0000" Y="31.0000" />
                        <AnchorPoint ScaleY="0.5000" />
                        <Position />
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
                    <Position X="55.0000" Y="30.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="0.5000" />
                    <PreSize X="0.0000" Y="0.0000" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleY="0.5000" />
                <Position X="500.0000" Y="50.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.8197" Y="0.5000" />
                <PreSize X="0.1803" Y="0.6000" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Normal" Path="Resource/UI/button_disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Resource/UI/button_down.png" Plist="" />
                <NormalFileData Type="Normal" Path="Resource/UI/button_up.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_Max" Visible="False" ActionTag="1565845575" Tag="95" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="520.0000" RightMargin="36.0000" TopMargin="35.5000" BottomMargin="35.5000" FontSize="22" LabelText="MAX" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                <Size X="54.0000" Y="29.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="520.0000" Y="50.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="0" B="0" />
                <PrePosition X="0.8525" Y="0.5000" />
                <PreSize X="0.0885" Y="0.2900" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <OutlineColor A="255" R="0" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <SingleColor A="255" R="45" G="37" B="19" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>