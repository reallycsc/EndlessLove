<GameFile>
  <PropertyGroup Name="GameOverLayer" Type="Layer" ID="4cdabc1b-fa95-4e02-a72f-9da88067cc1d" Version="2.3.3.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="60" Speed="1.0000">
        <Timeline ActionTag="515721989" Property="Position">
          <PointFrame FrameIndex="0" X="480.0000" Y="390.0000">
            <EasingData Type="29" />
          </PointFrame>
          <PointFrame FrameIndex="60" X="480.0000" Y="390.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="515721989" Property="Scale">
          <ScaleFrame FrameIndex="0" X="0.5000" Y="0.5000">
            <EasingData Type="29" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="60" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="515721989" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="29" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="60" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Layer" Tag="154" ctype="GameLayerObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="Panel_GameOver" ActionTag="1417019952" Tag="172" IconVisible="False" LeftMargin="130.0000" RightMargin="130.0000" TopMargin="95.0000" BottomMargin="95.0000" TouchEnable="True" BackColorAlpha="191" ComboBoxIndex="1" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
            <Size X="700.0000" Y="450.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="0" G="0" B="0" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.7292" Y="0.7031" />
            <SingleColor A="255" R="0" G="0" B="0" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="Text_GameOver" ActionTag="857765707" Tag="156" IconVisible="False" LeftMargin="283.0000" RightMargin="283.0000" TopMargin="90.5000" BottomMargin="450.5000" FontSize="72" LabelText="Game Over" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
            <Size X="394.0000" Y="99.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="500.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="0" B="0" />
            <PrePosition X="0.5000" Y="0.7813" />
            <PreSize X="0.4104" Y="0.1547" />
            <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
            <OutlineColor A="255" R="0" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Node_EnlargeAnimation" ActionTag="515721989" Tag="49" IconVisible="True" LeftMargin="480.0000" RightMargin="480.0000" TopMargin="250.0000" BottomMargin="390.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="Text_Highscore" ActionTag="1479945890" Tag="176" IconVisible="False" LeftMargin="-109.5000" RightMargin="-109.5000" TopMargin="-62.0000" BottomMargin="10.0000" FontSize="36" LabelText="Highscore: 0" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="219.0000" Y="52.0000" />
                <AnchorPoint ScaleX="0.5000" />
                <Position Y="10.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <OutlineColor A="255" R="0" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Node_GoldNumber" ActionTag="-1604196190" Tag="46" IconVisible="True" TopMargin="20.0000" BottomMargin="-20.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="Sprite_GoldCoin" ActionTag="-1732405529" Tag="47" IconVisible="False" HorizontalEdge="LeftEdge" VerticalEdge="TopEdge" LeftMargin="-57.0000" RightMargin="5.0000" TopMargin="-26.0000" BottomMargin="-26.0000" ctype="SpriteObjectData">
                    <Size X="52.0000" Y="52.0000" />
                    <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                    <Position X="-5.0000" />
                    <Scale ScaleX="0.6000" ScaleY="0.6000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="Resource/goldCoin.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_GoldNumber" ActionTag="242661703" Tag="48" IconVisible="False" HorizontalEdge="LeftEdge" VerticalEdge="TopEdge" LeftMargin="5.0000" RightMargin="-50.0000" TopMargin="-19.5000" BottomMargin="-58.5000" FontSize="28" LabelText="X 0&#xA;" HorizontalAlignmentType="HT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="45.0000" Y="78.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="5.0000" Y="-19.5000" />
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
                <Position Y="-20.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="480.0000" Y="390.0000" />
            <Scale ScaleX="0.5000" ScaleY="0.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.6094" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="Button_Retry" ActionTag="-1708568159" Tag="157" IconVisible="False" LeftMargin="305.0000" RightMargin="505.0000" TopMargin="475.0000" BottomMargin="115.0000" TouchEnable="True" FontSize="24" ButtonText="Retry" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="150.0000" Y="50.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="380.0000" Y="140.0000" />
            <Scale ScaleX="0.9815" ScaleY="1.0000" />
            <CColor A="255" R="173" G="216" B="230" />
            <PrePosition X="0.3958" Y="0.2188" />
            <PreSize X="0.1563" Y="0.0781" />
            <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
            <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Button_MainMenu" ActionTag="807690504" Tag="158" IconVisible="False" LeftMargin="505.0000" RightMargin="305.0000" TopMargin="475.0000" BottomMargin="115.0000" TouchEnable="True" FontSize="24" ButtonText="Main Menu" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="150.0000" Y="50.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="580.0000" Y="140.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="173" G="216" B="230" />
            <PrePosition X="0.6042" Y="0.2188" />
            <PreSize X="0.1563" Y="0.0781" />
            <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
            <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="ScrollView_EndingStory" ActionTag="344688501" Tag="48" IconVisible="False" LeftMargin="179.9999" RightMargin="180.0001" TopMargin="310.0000" BottomMargin="190.0000" TouchEnable="True" ClipAble="True" BackColorAlpha="127" ComboBoxIndex="2" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" IsBounceEnabled="True" ScrollDirectionType="Vertical" ctype="ScrollViewObjectData">
            <Size X="600.0000" Y="140.0000" />
            <Children>
              <AbstractNodeData Name="Text_EndingStory" ActionTag="-1713780221" Tag="20" IconVisible="False" LeftMargin="11.0000" RightMargin="494.0000" TopMargin="10.0000" BottomMargin="264.0000" FontSize="20" LabelText="Text Label" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                <Size X="95.0000" Y="26.0000" />
                <AnchorPoint ScaleY="1.0000" />
                <Position X="11.0000" Y="290.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.0183" Y="0.9667" />
                <PreSize X="0.1583" Y="0.0867" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="0" G="0" B="0" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="479.9999" Y="260.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.4063" />
            <PreSize X="0.6250" Y="0.2188" />
            <SingleColor A="255" R="255" G="150" B="100" />
            <FirstColor A="255" R="30" G="144" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
            <InnerNodeSize Width="600" Height="300" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>