<?php $id = (isset($_GET['id'])) ? htmlspecialchars(filter_input(INPUT_GET, 'id'), ENT_QUOTES) : uniqid(); ?>

<div class="card my-2" id="<?= $id; ?>">
    <input type="text" name="<?= $id; ?>" value="brick" hidden="hidden">
    <div class="card-header bg-info h2 text-white"><i class="fas fa-cube"></i> Object - Brick</div>
    <div class="card-body">
        <div class="row">
            <div class="col-3">
                <h4>Point A</h4>

                <input type="number" class="form-control" name="<?= $id; ?>_pointAX" placeholder="X" required>
                <input type="number" class="form-control" name="<?= $id; ?>_pointAY" placeholder="Y"required>
                <input type="number" class="form-control" name="<?= $id; ?>_pointAZ" placeholder="Z"required>
            </div>
            <div class="col-3">
                <h4>Point B</h4>

                <input type="number" class="form-control" name="<?= $id; ?>_pointBX" placeholder="X" required>
                <input type="number" class="form-control" name="<?= $id; ?>_pointBY" placeholder="Y"required>
                <input type="number" class="form-control" name="<?= $id; ?>_pointBZ" placeholder="Z"required>
            </div><div class="col-3">
                <h4>Point C</h4>

                <input type="number" class="form-control" name="<?= $id; ?>_pointCX" placeholder="X" required>
                <input type="number" class="form-control" name="<?= $id; ?>_pointCY" placeholder="Y"required>
                <input type="number" class="form-control" name="<?= $id; ?>_pointCZ" placeholder="Z"required>
            </div>
            <div class="col-3">
                <h4>Point D</h4>

                <input type="number" class="form-control" name="<?= $id; ?>_pointDX" placeholder="X" required>
                <input type="number" class="form-control" name="<?= $id; ?>_pointDY" placeholder="Y"required>
                <input type="number" class="form-control" name="<?= $id; ?>_pointDZ" placeholder="Z"required>
            </div>
        </div>
        <div class="row">
            <div class="col-3">
                <h4>Point E</h4>

                <input type="number" class="form-control" name="<?= $id; ?>_pointEX" placeholder="X" required>
                <input type="number" class="form-control" name="<?= $id; ?>_pointEY" placeholder="Y"required>
                <input type="number" class="form-control" name="<?= $id; ?>_pointEZ" placeholder="Z"required>
            </div>
            <div class="col-3">
                <h4>Point F</h4>

                <input type="number" class="form-control" name="<?= $id; ?>_pointFX" placeholder="X" required>
                <input type="number" class="form-control" name="<?= $id; ?>_pointFY" placeholder="Y"required>
                <input type="number" class="form-control" name="<?= $id; ?>_pointFZ" placeholder="Z"required>
            </div><div class="col-3">
                <h4>Point G</h4>

                <input type="number" class="form-control" name="<?= $id; ?>_pointGX" placeholder="X" required>
                <input type="number" class="form-control" name="<?= $id; ?>_pointGY" placeholder="Y"required>
                <input type="number" class="form-control" name="<?= $id; ?>_pointGZ" placeholder="Z"required>
            </div>
            <div class="col-3">
                <h4>Point H</h4>

                <input type="number" class="form-control" name="<?= $id; ?>_pointHX" placeholder="X" required>
                <input type="number" class="form-control" name="<?= $id; ?>_pointHY" placeholder="Y"required>
                <input type="number" class="form-control" name="<?= $id; ?>_pointHZ" placeholder="Z"required>
            </div>
        </div>

        <h4>Color</h4>

        <input type="number" class="form-control"name="<?= $id; ?>_colorR" placeholder="R" required>
        <input type="number" class="form-control"name="<?= $id; ?>_colorG" placeholder="G" required>
        <input type="number" class="form-control"name="<?= $id; ?>_colorB" placeholder="B" required>

        <div class="text-right mt-3">
            <a href="#objects" class="btn btn-danger" data-remove="<?= $id; ?>"><i class="fas fa-trash"></i> Remove</a>
        </div>
    </div>
</div>