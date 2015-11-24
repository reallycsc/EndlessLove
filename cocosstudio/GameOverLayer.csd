<GameFile>
  <PropertyGroup Name="GameOverLayer" Type="Layer" ID="4cdabc1b-fa95-4e02-a72f-9da88067cc1d" Version="2.3.3.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="60" Speed="1.0000">
        <Timeline ActionTag="515721989" Property="Position">
          <PointFrame FrameIndex="0" X="300.0000" Y="300.0000">
            <EasingData Type="29" />
          </PointFrame>
          <PointFrame FrameIndex="60" X="300.0000" Y="280.0000">
            <EasingData Type="29" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="515721989" Property="Scale">
          <ScaleFrame FrameIndex="0" X="0.5000" Y="0.5000">
            <EasingData Type="29" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="60" X="1.0000" Y="1.0000">
            <EasingData Type="29" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="515721989" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="29" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="60" X="0.0000" Y="0.0000">
            <EasingData Type="29" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Layer" Tag="154" ctype="GameLayerObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="Panel_GameOver" ActionTag="1417019952" Tag="172" IconVisible="False" LeftMargin="180.0000" RightMargin="180.0000" TopMargin="95.0000" BottomMargin="95.0000" TouchEnable="True" ClipAble="True" BackColorAlpha="191" ComboBoxIndex="1" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
            <Size X="600.0000" Y="450.0000" />
            <Children>
              <AbstractNodeData Name="Text_GameOver" ActionTag="857765707" Tag="156" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="102.0000" RightMargin="102.0000" BottomMargin="347.0000" FontSize="72" LabelText="Game Over" OutlineSize="4" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                <Size X="396.0000" Y="103.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
                <Position X="300.0000" Y="450.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="1.0000" />
                <PreSize X="0.6600" Y="0.2289" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="0" G="0" B="0" />
              </AbstractNodeData>
              <AbstractNodeData Name="Node_EnlargeAnimation" ActionTag="515721989" Tag="49" IconVisible="True" PositionPercentXEnabled="True" LeftMargin="300.0000" RightMargin="300.0000" TopMargin="169.9045" BottomMargin="280.0955" ctype="SingleNodeObjectData">
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
                  <AbstractNodeData Name="Node_GoldNumber" ActionTag="2099254852" Tag="139" IconVisible="True" PositionPercentXEnabled="True" TopMargin="10.0000" BottomMargin="-10.0000" ctype="SingleNodeObjectData">
                    <Size X="0.0000" Y="0.0000" />
                    <Children>
                      <AbstractNodeData Name="Sprite_GoldCoin" ActionTag="-1426789647" Tag="140" IconVisible="False" HorizontalEdge="LeftEdge" VerticalEdge="TopEdge" LeftMargin="-57.0000" RightMargin="5.0000" TopMargin="-26.0000" BottomMargin="-26.0000" ctype="SpriteObjectData">
                        <Size X="52.0000" Y="52.0000" />
                        <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                        <Position X="-5.0000" />
                        <Scale ScaleX="0.6000" ScaleY="0.6000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition />
                        <PreSize X="0.0000" Y="0.0000" />
                        <FileData Type="Normal" Path="Resource/Item/goldCoin.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_GoldNumber" ActionTag="-1324585572" Tag="141" IconVisible="False" HorizontalEdge="LeftEdge" VerticalEdge="TopEdge" LeftMargin="5.0000" RightMargin="-24.0000" TopMargin="-19.5000" BottomMargin="-19.5000" FontSize="28" LabelText="0" HorizontalAlignmentType="HT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="19.0000" Y="39.0000" />
                        <AnchorPoint ScaleY="0.5000" />
                        <Position X="5.0000" />
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
                    <Position Y="-10.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="300.0000" Y="280.0955" />
                <Scale ScaleX="0.9976" ScaleY="0.9976" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.6224" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="ScrollView_EndingStory" Visible="False" ActionTag="344688501" VisibleForFrame="False" Tag="48" IconVisible="False" PositionPercentXEnabled="True" TopMargin="200.0000" BottomMargin="110.0000" TouchEnable="True" ClipAble="True" BackColorAlpha="127" ComboBoxIndex="2" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" IsBounceEnabled="True" ScrollDirectionType="Vertical" ctype="ScrollViewObjectData">
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
                <Position X="300.0000" Y="180.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.4000" />
                <PreSize X="1.0000" Y="0.3111" />
                <SingleColor A="255" R="255" G="150" B="100" />
                <FirstColor A="255" R="30" G="144" B="255" />
                <EndColor A="255" R="255" G="255" B="255" />
                <ColorVector ScaleY="1.0000" />
                <InnerNodeSize Width="600" Height="300" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_Retry" ActionTag="-1708568159" Tag="157" IconVisible="False" LeftMargin="125.0000" RightMargin="325.0000" TopMargin="360.0000" BottomMargin="40.0000" TouchEnable="True" FontSize="24" ButtonText="Retry" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="120" Scale9Height="28" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="150.0000" Y="50.0000" />
                <AnchorPoint ScaleX="0.5000" />
                <Position X="200.0000" Y="40.0000" />
                <Scale ScaleX="0.9815" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.3333" Y="0.0889" />
                <PreSize X="0.2500" Y="0.1111" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Normal" Path="Resource/UI/button_disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Resource/UI/button_down.png" Plist="" />
                <NormalFileData Type="Normal" Path="Resource/UI/button_up.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_MainMenu" ActionTag="807690504" Tag="158" IconVisible="False" LeftMargin="325.0000" RightMargin="125.0000" TopMargin="360.0000" BottomMargin="40.0000" TouchEnable="True" FontSize="24" ButtonText="Main Menu" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="120" Scale9Height="28" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="150.0000" Y="50.0000" />
                <AnchorPoint ScaleX="0.5000" />
                <Position X="400.0000" Y="40.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.6667" Y="0.0889" />
                <PreSize X="0.2500" Y="0.1111" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Normal" Path="Resource/UI/button_disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Resource/UI/button_down.png" Plist="" />
                <NormalFileData Type="Normal" Path="Resource/UI/button_up.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_Revive" ActionTag="1202742161" Tag="127" IconVisible="False" LeftMargin="125.0000" RightMargin="325.0000" TopMargin="250.0000" BottomMargin="150.0000" TouchEnable="True" FontSize="24" ButtonText="Revive" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="120" Scale9Height="28" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="150.0000" Y="50.0000" />
                <Children>
                  <AbstractNodeData Name="Sprite_playAd" ActionTag="-247966633" Tag="138" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="55.5000" RightMargin="55.5000" TopMargin="54.0000" BottomMargin="-36.0000" ctype="SpriteObjectData">
                    <Size X="39.0000" Y="32.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="75.0000" Y="-20.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="-0.4000" />
                    <PreSize X="0.2600" Y="0.6400" />
                    <FileData Type="Normal" Path="Resource/playAd.png" Plist="" />
                    <BlendFunc Src="770" Dst="771" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" />
                <Position X="200.0000" Y="150.0000" />
                <Scale ScaleX="0.9815" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.3333" Y="0.3333" />
                <PreSize X="0.2500" Y="0.1111" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Normal" Path="Resource/UI/button_disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Resource/UI/button_orange_down.png" Plist="" />
                <NormalFileData Type="Normal" Path="Resource/UI/button_orange_up.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_DoubleCoin" ActionTag="41990261" Tag="142" IconVisible="False" LeftMargin="325.0000" RightMargin="125.0000" TopMargin="250.0000" BottomMargin="150.0000" TouchEnable="True" FontSize="24" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="120" Scale9Height="28" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="150.0000" Y="50.0000" />
                <Children>
                  <AbstractNodeData Name="Node_GoldNumber" ActionTag="-1181320184" Tag="143" IconVisible="True" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="75.0000" RightMargin="75.0000" TopMargin="25.0000" BottomMargin="25.0000" ctype="SingleNodeObjectData">
                    <Size X="0.0000" Y="0.0000" />
                    <Children>
                      <AbstractNodeData Name="Sprite_GoldCoin" ActionTag="91215662" Tag="144" IconVisible="False" HorizontalEdge="LeftEdge" VerticalEdge="TopEdge" LeftMargin="-67.0000" RightMargin="15.0000" TopMargin="-26.0000" BottomMargin="-26.0000" ctype="SpriteObjectData">
                        <Size X="52.0000" Y="52.0000" />
                        <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                        <Position X="-15.0000" />
                        <Scale ScaleX="0.6000" ScaleY="0.6000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition />
                        <PreSize X="0.0000" Y="0.0000" />
                        <FileData Type="Normal" Path="Resource/Item/goldCoin.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_GoldNumber" ActionTag="1566928842" Tag="145" IconVisible="False" HorizontalEdge="LeftEdge" VerticalEdge="TopEdge" LeftMargin="-11.0000" RightMargin="-35.0000" TopMargin="-19.5000" BottomMargin="-19.5000" FontSize="28" LabelText="X 2" HorizontalAlignmentType="HT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="46.0000" Y="39.0000" />
                        <AnchorPoint ScaleY="0.5000" />
                        <Position X="-11.0000" />
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
                    <Position X="75.0000" Y="25.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="0.5000" />
                    <PreSize X="0.0000" Y="0.0000" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Sprite_playAd" ActionTag="1960756069" Tag="146" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="55.5000" RightMargin="55.5000" TopMargin="54.0000" BottomMargin="-36.0000" ctype="SpriteObjectData">
                    <Size X="39.0000" Y="32.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="75.0000" Y="-20.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="-0.4000" />
                    <PreSize X="0.2600" Y="0.6400" />
                    <FileData Type="Normal" Path="Resource/playAd.png" Plist="" />
                    <BlendFunc Src="770" Dst="771" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" />
                <Position X="400.0000" Y="150.0000" />
                <Scale ScaleX="0.9815" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.6667" Y="0.3333" />
                <PreSize X="0.2500" Y="0.1111" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Normal" Path="Resource/UI/button_disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Resource/UI/button_orange_down.png" Plist="" />
                <NormalFileData Type="Normal" Path="Resource/UI/button_orange_up.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.6250" Y="0.7031" />
            <SingleColor A="255" R="26" G="26" B="26" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>