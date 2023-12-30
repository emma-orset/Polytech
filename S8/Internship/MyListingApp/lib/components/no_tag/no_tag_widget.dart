import '/flutter_flow/flutter_flow_theme.dart';
import '/flutter_flow/flutter_flow_util.dart';
import 'package:flutter/material.dart';
import 'package:flutter_spinkit/flutter_spinkit.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';
import 'no_tag_model.dart';
export 'no_tag_model.dart';

class NoTagWidget extends StatefulWidget {
  const NoTagWidget({Key? key}) : super(key: key);

  @override
  _NoTagWidgetState createState() => _NoTagWidgetState();
}

class _NoTagWidgetState extends State<NoTagWidget> {
  late NoTagModel _model;

  @override
  void setState(VoidCallback callback) {
    super.setState(callback);
    _model.onUpdate();
  }

  @override
  void initState() {
    super.initState();
    _model = createModel(context, () => NoTagModel());
  }

  @override
  void dispose() {
    _model.maybeDispose();

    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Align(
      alignment: AlignmentDirectional(0.0, 0.0),
      child: Text(
        'No Tag for the moment. ',
        textAlign: TextAlign.center,
        style: FlutterFlowTheme.of(context).bodyMedium,
      ),
    );
  }
}
